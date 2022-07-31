#include <iostream>
#include "lex/token.h"

int main(int argc, char *argv[]) {
    // make a tokenbuffer
    TokenBuffer* token_buffer = new TokenBuffer(1);
    // fake token (what)
    char* value = "what";
    Token* token = new Token(value, ::IDENTIFIER);

    token_buffer->push(token);

    std::cout << "k: " << token_buffer->size() << std::endl;
}