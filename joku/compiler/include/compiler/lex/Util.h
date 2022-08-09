#ifndef __UTIL_LEX_H__
#define __UTIL_LEX_H__

#include <vector>
#include <iostream>
#include <optional>
#include "compiler/util/Stream.hpp"
#include "compiler/lex/Token.h"

namespace joku::compiler::lexer
{
    std::optional<Token> consume_whitespace(Stream<char> *stream);

    std::optional<Token> consume_comment(Stream<char> *stream);

    std::optional<Token> consume_op(Stream<char> *stream);
}

#endif