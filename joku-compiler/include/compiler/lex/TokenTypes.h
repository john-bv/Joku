#ifndef __TOKEN_TYPES_H__
#define __TOKEN_TYPES_H__

#include "compiler/util/Stream.hpp"

namespace joku::compiler::token_util
{
    char *get_comment(Stream<char> *stream);
    bool is_whitespace(char c);
}

#endif