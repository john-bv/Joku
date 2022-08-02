#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include "lex/tokenbuffer.h"
#include <string>

TokenBuffer nvscript_tokenize_stdstr(std::string v);

#endif