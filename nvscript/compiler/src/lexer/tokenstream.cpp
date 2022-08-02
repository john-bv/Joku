#include "lex/tokenstream.h"

/**
 * @brief Construct a new Token Stream object.
 */
TokenStream();

/**
 * @brief Consumes the token in the stream, giving you the next token.
 */
void peek();

void peek(int amt);

bool is_eof();

/**
 * @brief Returns the amount of tokens that have been consumed.
 * @return int
 */
int consumed();

/**
 * @brief Return a token at given position ahead. (Null token if out of bounds)
 */
Token* nth();

/**
 * @brief Return the next token in the stream.
 */
Token* nth(int n);

Token* first() {
    return nth(0);
}

Token* second() {
    return nth(1);
}

Token* third() {
    return nth(2);
}

TokenStream sub_token(int from, int to);

/**
 * @brief Returns the tokens that are left in the stream.
 * This is CLONED, so you can't modify the actual buffer.
 */
std::vector<Token> tokens();