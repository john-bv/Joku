#include <vector>
#include "compiler/lex/Token.h"

using namespace joku::compiler;

Token::Token()
{
    this->value = nullptr;
    this->variant = TokenType::END_OF_FILE;
    this->start = 0;
    this->end = 0;
    this->buffer = nullptr;
}

Token::Token(std::string v, TokenType::TokenVariant variant, int start, int end, int *buffer_id)
{
    this->value = v;
    this->variant = variant;
    this->start = start;
    this->end = end;
    this->buffer = buffer_id;
}

TokenType::TokenVariant Token::get_variant()
{
    return variant;
}

std::string Token::get_name()
{
    switch (this->variant)
    {
        case TokenType::END_OF_FILE:
            return "END_OF_FILE";
        case TokenType::WHITESPACE:
            return "WHITESPACE";
        case TokenType::COMMENT:
            return "COMMENT";
        case TokenType::COMMENT_SINGLE:
            return "COMMENT_SINGLE";
        case TokenType::UNKNOWN:
            return "UNKNOWN";
        case TokenType::IDENTIFIER:
            return "IDENTIFIER";
        case TokenType::LITERAL_CHAR:
            return "LITERAL_CHAR";
        case TokenType::LITERAL_STRING:
            return "LITERAL_STRING";
        case TokenType::LITERAL_NUMBER:
            return "LITERAL_NUMBER";
        case TokenType::OPERATOR:
            return "OPERATOR";
        case TokenType::ACCESSOR:
            return "ACCESSOR";
        case TokenType::LEFT_BRACKET:
            return "LEFT_BRACKET";
        case TokenType::RIGHT_BRACKET:
            return "RIGHT_BRACKET";
        case TokenType::LEFT_PAREN:
            return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN:
            return "RIGHT_PAREN";
        case TokenType::LEFT_BRACE:
            return "LEFT_BRACE";
        case TokenType::RIGHT_BRACE:
            return "RIGHT_BRACE";
        case TokenType::STATEMENT_END:
            return "STATEMENT_END";
        case TokenType::COMMA:
            return "COMMA";
        case TokenType::REVERSE_SLASH:
            return "REVERSE_SLASH";
        case TokenType::PUNCTUATOR:
            return "PUNCTUATOR";
        default:
            return "UNKNOWN";
    }
}

void Token::set_position(int position)
{
    position = position;
}

bool Token::is_null()
{
    return value.length() == 0;
}

int Token::belongs_to()
{
    return this->buffer == nullptr ? -1 : *this->buffer;
}