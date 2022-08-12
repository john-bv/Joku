/**
 * @warning Stay clear of anything in here. this is internal api for a reason.
 * You should not be using any macros in here.
 */
#include "compiler/lex/Util.h"
#include "compiler/lex/Tokenize.h"
#include "compiler/lex/TokenTypes.h"
#include <vector>
#include <iostream>
#include <optional>

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
                CONSUME_STD_STRING(values, stream, [&](char c){ return c != '*'; });
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
    std::optional<Token> consume_op(Stream<char> *stream)
    {
        char *c = stream->first();

        char operations[] = {'+', '-', '*', '/', '%', '=', '!', '<', '>', '&', '|', '^', '~', '?'};

        if (std::end(operations) != std::find(std::begin(operations), std::end(operations), *c))
        {
            POS_START(stream);
            char c_seg = stream->peek().value();
            POS_END(stream);
            std::string segment = {c_seg};
            return INIT_TOKEN(segment, TokenType::OPERATOR);
        }
        else
        {
            return std::nullopt;
        }
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

    /**
     * @brief Consumes a literal from the stream.
     *
     * Here we're mainly concerned about the following:
     * - strings
     * - numbers
     * - chars
     *
     * Keep in mind these values aren't actually parsed, just identified.
     */
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
};