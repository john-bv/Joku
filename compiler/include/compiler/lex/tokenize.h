#ifndef __TOKENIZE_H__
#define __TOKENIZE_H__

#include "compiler/lex/TokenStream.h"
// #include "compiler/lex/TokenTypes.h"
#include "compiler/util/Stream.hpp"
#include <deque>

TokenStream *tokenize_str(char *source, int len);

#endif