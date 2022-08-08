#ifndef __TOKEN_STREAM_H__
#define __TOKEN_STREAM_H__

#include "compiler/lex/Token.h"
#include <deque>

namespace joku
{
    namespace compiler
    {
        class TokenStream
        {
            private:
                /**
                 * @brief The cursor position in the token buffer.
                 */
                int position;
                /**
                 * @brief The initial length of the stream.
                 */
                int ilen;
                /**
                 * @brief The ID of this stream (relevant to the parser)
                 */
                int id;
                /**
                 * @brief Whether or not to allow the token buffer to be resized. (externally)
                 */
                bool allow_resize;
                /**
                 * @brief The last Token that was read.
                 */
                Token last_token;
                /**
                 * @brief A dynamically allocated array of tokens.
                 * This will change as the stream is parsed.
                 */
                std::deque<Token> token_buffer;

            public:
                /**
                 * @brief Construct a new Token Stream object.
                 */
                TokenStream();

                /**
                 * @brief Consumes the token in the stream, giving you the next token.
                 */
                Token peek();

                TokenStream* peek(int amt);

                void push(Token token);

                bool is_eof();

                /**
                 * @brief Returns the amount of tokens that have been consumed.
                 * @return int
                 */
                int consumed();

                int size();

                /**
                 * @brief Return a token at given position ahead. (Null token if out of bounds)
                 */
                Token *nth();

                /**
                 * @brief Return the next token in the stream.
                 */
                Token* nth(int n);

                Token *first() {
                    return nth(0);
                }

                Token *second() {
                    return nth(1);
                }

                Token *third() {
                    return nth(2);
                }

                TokenStream *sub_token(int from, int to);

                /**
                 * @brief Returns the tokens that are left in the stream.
                 * This is CLONED, so you can't modify the actual buffer.
                 */
                std::vector<Token> tokens();
        };
    };
}
#endif