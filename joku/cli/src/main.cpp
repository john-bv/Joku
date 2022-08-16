#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include "compiler/util/Stream.hpp"
#include "compiler/lex/Token.h"
#include "compiler/lex/Tokenize.h"

using namespace joku::compiler;

int main(int argc, char* argv[])
{
    // Check if there is a file to read from
    if (argc < 2)
    {
        std::cout << "No file to read from" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);

    std::string contents(std::istreambuf_iterator<char>{file}, {});

    Stream<Token> *stream = joku::compiler::tokenizer::tokenize_str((char *)contents.c_str(), contents.length());

    while (!stream->is_eof())
    {
        Token token = stream->peek().value();
        printf("[Token:%s] %s\n", token.get_name().c_str(), token.get_value().c_str());
    }

    printf("Done\n");

    return 0;
}