#include <vector>
#include "lex/token.h"

Token::Token() {
    value = nullptr;
    variant = ::END_OF_FILE;
    position = 0;
    buffer_id = 0;
}

Token::Token(char* v, TokenVariant variant, int position, int buffer_id) {
    value = v;
    this->variant = variant;
    this->position = position;
    this->buffer_id = buffer_id;
}

TokenVariant Token::get_variant() {
    return variant;
}

void Token::set_position(int position) {
    position = position;
}

bool Token::is_null() {
    return value == nullptr;
}

int Token::belongs_to() {
    return buffer_id;
}

TokenBuffer::TokenBuffer(int id) {
    tokens = std::vector<Token>();
    previous_token = Token();
    id = id;
    current_position = 0;
}

TokenBuffer::~TokenBuffer() {
    tokens.clear();
}

/**
 * @brief Get the next token object, but does not increment the position.
 * @return Token
 */
Token TokenBuffer::get_next() {
    if (available()) {
        return tokens[current_position + 1];
    } else {
        return Token();
    }
}

/**
 * @brief Get the next token object
 * @return Token
 */
Token TokenBuffer::get_current() {
    return tokens[current_position];
}

/**
 * @brief Get the previous token object
 * @return Token
 */
Token TokenBuffer::get_previous() {
    return previous_token;
}

Token TokenBuffer::get_at(int position) {
    if (position > tokens.size()) {
        return Token();
    }

    return tokens[position];
}

void TokenBuffer::push(Token *token) {
    token->set_position(tokens.size());
    this->tokens.push_back(*token);
}

int TokenBuffer::size() {
    return this->tokens.size();
}

int TokenBuffer::get_id() {
    return id;
}

int TokenBuffer::get_position() {
    return current_position;
}