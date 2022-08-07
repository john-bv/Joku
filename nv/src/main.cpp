#include <iostream>
#include "compiler/util/Stream.hpp"
#include "compiler/lex/Token.h"
// #include "compiler/lex/tokenize.h"

int main()
{
    std::cout << "Ok, this is entry !?" << std::endl;
    const char *test = "test dog test todsa"; // null terminator for length
    // tokenize_str((char *)test);
    // this is a test to test stream.
    // Stream<Token> *stream = new Stream<Token>();
    Stream<char> *source_buff = Stream<char>::from_ptr((char *)test, 20);
    Stream<char> *what = source_buff->sub_items(1, 4); // shuold be "est"

    for (char item: what->items())
    {
        std::cout << "source_buff->sub_items(1, 4) = " << item << std::endl;
    }


    auto c = what->peek();

    if (!c.has_value())
    {
        std::cout << "nullptr" << std::endl;
    }
    else
    {
        std::cout << "source_buff->peek() = " << c.value() << std::endl;
    }
}