#include <iostream>
#include "lex/tokenize.h"

int main()
{
    std::cout << "Ok, this is entry !?" << std::endl;
    char *test = "test";
    tokenize_str(test);
}