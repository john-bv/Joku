#ifndef __TOKENIZE_H__
#define __TOKENIZE_H__

#include "compiler/lex/Token.h"
#include "compiler/util/Stream.hpp"

using namespace joku::compiler;

namespace joku::compiler::tokenizer
{
    Stream<Token> *tokenize_str(char *source, int len);
}

#endif