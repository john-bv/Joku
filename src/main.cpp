#include <iostream>
#include "lex/token.h"

int main(int argc, char *argv[]) {
    // make a tokenbuffer
    TokenBuffer* token_buffer = new TokenBuffer(1);
    // fake token (what)
    Token* token = new Token("what", ::IDENTIFIER);

    // add token to buffer
    token_buffer->push(*token);

    std::cout << "k: " << token_buffer->size() << std::endl;
}