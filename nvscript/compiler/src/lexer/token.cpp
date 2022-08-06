#include <vector>
#include "lex/token.h"
#include "lex/TokenStream.h"

Token::Token()
{
    this->value = nullptr;
    this->variant = ::END_OF_FILE;
    this->position = 0;
    this->buffer = nullptr;
}

Token::Token(char *v, TokenVariant variant, int position, int *buffer_id)
{
    this->value = v;
    this->variant = variant;
    this->position = position;
    this->buffer = buffer_id;
}

TokenVariant Token::get_variant()
{
    return variant;
}

void Token::set_position(int position)
{
    position = position;
}

bool Token::is_null()
{
    return value == nullptr;
}

int Token::belongs_to()
{
    return this->buffer == nullptr ? -1 : *this->buffer;
}