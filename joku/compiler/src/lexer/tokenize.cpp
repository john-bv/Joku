#include "compiler/lex/tokenize.h"
#include <iostream>
#include <optional>

TokenStream *tokenize_str(char *str, int len)
{
    // Stream of chars
    Stream<char> *source_buff = Stream<char>::from_ptr(str, len);
    TokenStream *stream = new TokenStream();

    while (!source_buff->is_eof())
    {
        // boiler code for now
        std::optional<char> c = source_buff->peek();
        std::cout << c.value() << std::endl;
    }

    return stream;
}