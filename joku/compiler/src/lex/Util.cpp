/**
 * @warning Stay clear of anything in here. this is internal api for a reason.
 * You should not be using any macros in here.
 */
#include "compiler/lex/Util.h"

#define POS_START(stream) \
    int start = stream->get_position();
#define POS_END(stream) \
    int end = stream->get_position();
#define CONSUME_STD_STRING(name, stream, cb) \
    std::vector<char> _vals = stream->consume_while(cb); \
    std::string name = std::string(_vals.begin(), _vals.end()); \

/**
 * @brief This macro ASSUMES that POS_START and POS_END have been called.
 */
#define INIT_TOKEN(value, variant) Token(value, variant, start, end);

namespace joku::compiler::lexer
{
    std::optional<Token> consume_whitespace(Stream<char> *stream)
    {
        if (!isspace(*stream->first()))
        {
            return std::nullopt;
        }

        std::string segment;

        POS_START(stream);

        std::vector<char> values = stream->consume_while([&](char c){ return isspace(c); });

        POS_END(stream);

        segment.assign(values.begin(), values.end());

        return INIT_TOKEN(segment, TokenType::WHITESPACE);
    }

    std::optional<Token> consume_comment(Stream<char> *stream)
    {
        char *c = stream->first();

        if (*c == '/')
        {
            POS_START(stream);
            stream->peek();
            if (stream->first() != nullptr && *stream->first() == '/')
            {
                stream->peek();
                CONSUME_STD_STRING(values, stream, [&](char c){ return c != '\n'; });
                POS_END(stream);

                return INIT_TOKEN(values, TokenType::COMMENT_SINGLE);
            }
            else if (stream->first() != nullptr && *stream->first() == '*')
            {
                stream->peek();
                CONSUME_STD_STRING(values, stream, [&](char c){
                    if (c != '*')
                    {
                        if (stream->second() != nullptr && *stream->second() == '/')
                        {
                            return false;
                        }
                        else
                        {
                            return true;
                        }
                    }
                    return true;
                });
                POS_END(stream);

                return INIT_TOKEN(values, TokenType::COMMENT);
            }
            else
            {
                return std::nullopt;
            }
        }
        else if (*c == '#')
        {
            POS_START(stream);
            stream->peek();
            CONSUME_STD_STRING(values, stream, [](char c){ return c != '\n'; });
            POS_END(stream);

            return INIT_TOKEN(values, TokenType::COMMENT_SINGLE);
        }
        else
        {
            return std::nullopt;
        }
    }

    // Attempts to eat an operator from the given stream.
    std::optional<Token> consume_punctuator(Stream<char> *stream)
    {
        char *c = stream->first();

        char puncts[] = {'#', '$', '%', '+', '-', '*', '/', '%', '=', '!', '<', '>', '&', '|', '^', '~', '?'};

        if (std::end(puncts) != std::find(std::begin(puncts), std::end(puncts), *c))
        {
            POS_START(stream);
            char c_seg = stream->peek().value();
            POS_END(stream);
            std::string segment = {c_seg};
            return INIT_TOKEN(segment, TokenType::PUNCTUATOR);
        }
        else
        {
            return std::nullopt;
        }
    }

    std::optional<Token> consume_keyword(Stream<char> *stream)
    {
        std::string stack = "";

        // this is a segment that will be used to construct the keyword (if valid)
        for (int i = 0; i < kw::MAX_KEYWORD_LENGTH; i++)
        {
            char *next = stream->nth(i);

            if (next == nullptr) break;
            if (!isalpha(*next)) break;

            stack.push_back(*next);

            std::optional<kw::Keyword> word = kw::keyword_from_str(&stack);

            if (word.has_value())
            {
                // we're not done yet!
                // assert that the next char is a space or a newline
                char *next_char = stream->nth(i + 1);
                if (next_char != nullptr && (!isspace(*next_char) || *next_char == ';')) break;

                POS_START(stream);
                // we're peeking i + 1, because we need to account for nth(0)
                stream->peek(i + 1);
                POS_END(stream);
                return INIT_TOKEN(stack, TokenType::KEYWORD);
            }
        }

        return std::nullopt;
    }

    // Eats a indentifier from the given stream.
    // Keep in mind that these can NOT be keywords.
    // While a keyword as a identifier may not error at this stage,
    // it will error later on.
    std::optional<Token> consume_identifier(Stream<char> *stream)
    {
        char *c = stream->first();
        if (!isalpha(*c))
        {
            return std::nullopt;
        }

        POS_START(stream);
        CONSUME_STD_STRING(values, stream, [](char c){ return isalnum(c) || c == '_'; });
        POS_END(stream);

        return INIT_TOKEN(values, TokenType::IDENTIFIER);
    }

    std::optional<Token> consume_literal(Stream<char> *stream)
    {
        // first lets check chars and strings
        char *c = stream->first();

        if (*c == '\'')
        {
            // This is a char literal.
            stream->peek(); // we don't need the ' in the token
            POS_START(stream);
            CONSUME_STD_STRING(values, stream, [&](char c){
                if (c == '\'')
                {
                    // check if the previous char is a `\`
                    if (stream->prev().has_value() && (stream->prev().value() == '\\'))
                    {
                        return true;
                    }

                    // we need an extra peek here.
                    stream->peek();
                    return false;
                }
                else
                {
                    return true;
                }
            });
            POS_END(stream);
            return INIT_TOKEN(values, TokenType::LITERAL_CHAR);
        }
        else if (*c == '"' || *c == '`')
        {
            // the opening char is a double quote or a back tick, we need to peek.
            char opening = stream->peek().value();
            POS_START(stream);

            // @returns values = std::string
            CONSUME_STD_STRING(values, stream, [&](char c) {
                if (c == opening)
                {
                    // check if the previous char is a `\`, if so, this is an escape, and we should not consume it.
                    if (stream->prev().has_value() && (stream->prev().value() == '\\'))
                    {
                        return true;
                    }

                    // we need an extra peek here.
                    stream->peek();
                    return false;
                }
                else
                {
                    return true;
                }
            });

            POS_END(stream);

            return INIT_TOKEN(values, TokenType::LITERAL_STRING);
        }

        // check if this is a number
        // Keep in mind, literal numbers are parsed later,
        // the tokenizer doesn't give a shit about the actual value or what tokens
        // are next to it.
        else if (isdigit(*c))
        {
            POS_START(stream);

            CONSUME_STD_STRING(values, stream, [](char c){ return isdigit(c); });
            POS_END(stream);

            return INIT_TOKEN(values, TokenType::LITERAL_NUMBER);
        }
        else
        {
            return std::nullopt;
        }
    }

    std::optional<Token> consume_reserved(Stream<char> *stream)
    {
        char *c = stream->first();

        char reserved[] = {'[', ']', '{', '}', '(', ')', ';', ':', ',', '.'};

        // this is a little hacky, but bare with it
        if (*c == '.' || *c == ':')
        {
            // we need to check the second char.
            char *second = stream->second();

            if (second != nullptr && *second == '.' && *c == '.')
            {
                // this is a double dot.
                POS_START(stream);
                stream->peek(2);
                POS_END(stream);

                return INIT_TOKEN("..", TokenType::ACCESSOR);
            }
            else if (second != nullptr && *second == ':' && *c == ':')
            {
                // this is a double colon.
                POS_START(stream);
                stream->peek();
                POS_END(stream);
                return INIT_TOKEN("::", TokenType::PUNCTUATOR);
            }
        }

        if (std::end(reserved) != std::find(std::begin(reserved), std::end(reserved), *c))
        {
            // this char is in the reserved array, we can return it.
            POS_START(stream);
            stream->peek();
            POS_END(stream);
            // these are all one length, so a switch will suffice.
            switch(*c)
            {
                case '[':
                    return INIT_TOKEN("[", TokenType::LEFT_BRACKET);
                case ']':
                    return INIT_TOKEN("]", TokenType::RIGHT_BRACKET);
                case '{':
                    return INIT_TOKEN("{", TokenType::LEFT_BRACE);
                case '}':
                    return INIT_TOKEN("}", TokenType::RIGHT_BRACE);
                case '(':
                    return INIT_TOKEN("(", TokenType::LEFT_PAREN);
                case ')':
                    return INIT_TOKEN(")", TokenType::RIGHT_PAREN);
                case ';':
                    return INIT_TOKEN(";", TokenType::STATEMENT_END);
                case ':':
                    return INIT_TOKEN(":", TokenType::COLON);
                case ',':
                    return INIT_TOKEN(",", TokenType::COMMA);
                case '.':
                    return INIT_TOKEN(".", TokenType::ACCESSOR);
                default:
                    // This is an error because if this condition is ever reached,
                    // there is a bug in the code.
                    throw new std::exception();
            }
        }
        else
        {
            return std::nullopt;
        }
    }
};