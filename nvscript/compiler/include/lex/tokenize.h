#ifndef __TOKENIZE_H__
#define __TOKENIZE_H__

#include "lex/token.h"
#include "lex/TokenStream.h"
#include <deque>

TokenStream *tokenize_str(char *source);

#endif