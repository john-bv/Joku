#include "compiler/lex/TokenStream.h"

TokenStream::TokenStream()
{
    this->position = 0;
    this->ilen = 0;
    this->id = 0;
    this->last_token = Token();
    this->token_buffer = std::deque<Token>();
}

Token TokenStream::peek()
{
    if (this->allow_resize == true)
    {
        this->allow_resize = false;
    }

    // we need to make sure that we can peek at the next token
    if (this->token_buffer.size() < 1)
    {
        return Token();
    }
    else
    {
        this->position++;
        Token front = this->token_buffer.front();
        this->token_buffer.pop_front();
        return front;
    }
}

TokenStream *TokenStream::peek(int amt)
{
    if (this->token_buffer.size() < amt)
    {
        return nullptr;
    }
    else
    {
        TokenStream *stream = new TokenStream();
        for (int i = 0; i < amt; i++)
        {
            Token token = this->peek();
            if (token.is_null())
            {
                break;
            }
            stream->token_buffer.push_back(token);
        }

        if (stream->size() == 0)
        {
            delete stream;
            return nullptr;
        }
        else
        {
            return stream;
        }
    }
}

void TokenStream::push(Token token)
{
    if (this->allow_resize)
    {
        this->token_buffer.push_back(token);
    }
}

bool TokenStream::is_eof()
{
    return this->token_buffer.size() == 0 && this->position == this->ilen;
}

int TokenStream::consumed()
{
    return this->ilen - this->token_buffer.size();
}

int TokenStream::size()
{
    return this->token_buffer.size();
}

Token *TokenStream::nth()
{
    if (this->token_buffer.size() < 1)
    {
        return nullptr;
    }
    else
    {
        return &this->token_buffer.front();
    }
}

Token *TokenStream::nth(int n)
{
    if (this->token_buffer.size() < n)
    {
        return nullptr;
    }
    else
    {
        return &this->token_buffer.at(n);
    }
}

TokenStream *TokenStream::sub_token(int from, int to)
{
    if (this->token_buffer.size() < to || this->token_buffer.size() < from)
    {
        return nullptr;
    }
    else
    {
        TokenStream *stream = new TokenStream();
        for (int i = from; i < to; i++)
        {
            stream->token_buffer.push_back(this->token_buffer.at(i));
        }
        return stream;
    }
}

std::vector<Token> TokenStream::tokens()
{
    std::vector<Token> tokens = std::vector<Token>();
    for (int i = 0; i < this->token_buffer.size(); i++)
    {
        tokens.push_back(this->token_buffer.at(i));
    }
    return tokens;
}