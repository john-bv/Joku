#include "lex/tokenize.h"
#include <iostream>

TokenStream *tokenize_str(char *str)
{
    // Stream of chars
    Stream<char> *source_buff = Stream<char>::from_ptr(str);
    TokenStream *stream = new TokenStream();

    while (!source_buff->is_eof())
    {
        // boiler code for now
        char c = source_buff->peek();
        std::cout << c << std::endl;
    }

    return stream;
}