#include <iostream>
#include "compiler/util/Stream.h"
#include "lex/tokenize.h"

int main()
{
    std::cout << "Ok, this is entry !?" << std::endl;
    const char *test = "test";
    tokenize_str((char *)test);
}