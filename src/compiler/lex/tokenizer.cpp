#include "lex/tokenizer.h"
#include <iostream>

// Tokenize a string of characters into a list of tokens.
TokenBuffer tokenize_str(std::string v) {
    const char *cstr = v.data();
    TokenBuffer *buffer = new TokenBuffer();

    for (int i = 0; i < v.size(); i++) {
        std::cout << cstr[i] << std::endl;
    }
}