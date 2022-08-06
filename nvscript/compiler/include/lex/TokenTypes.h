#ifndef _TOKEN_TYPES_H_
#define _TOKEN_TYPES_H_

#include "compiler/util/Stream.h"

namespace token_util
{
    char *get_comment(Stream<char> *stream);
    bool is_whitespace(char c);
}

#endif