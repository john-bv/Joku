#ifndef __TOKENIZE_H__
#define __TOKENIZE_H__

#include "lex/TokenStream.h"
#include "lex/TokenTypes.h"
#include <deque>

TokenStream *tokenize_str(char *source);

#endif