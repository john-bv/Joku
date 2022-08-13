#ifndef __TOKENIZE_H__
#define __TOKENIZE_H__

#include <vector>
#include <iostream>
#include <optional>
#include "compiler/lex/TokenTypes.h"
#include "compiler/lex/Keyword.h"
#include "compiler/lex/Util.h"
#include "compiler/lex/Token.h"
#include "compiler/util/Stream.hpp"

using namespace joku::compiler;



namespace joku::compiler::tokenizer
{
    Stream<Token> *tokenize_str(char *source, int len);
}

#endif