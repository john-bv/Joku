#ifndef __UTIL_LEX_H__
#define __UTIL_LEX_H__

#include <vector>
#include <string>
#include <iostream>
#include <optional>
#include <exception>
#include "compiler/util/Stream.hpp"
#include "compiler/lex/Token.h"
#include "compiler/lex/Keyword.h"
#include "compiler/lex/TokenTypes.h"
#include "compiler/lex/Keyword.h"

namespace joku::compiler::lexer
{
    std::optional<Token> consume_whitespace(Stream<char> *stream);

    std::optional<Token> consume_comment(Stream<char> *stream);

    std::optional<Token> consume_punctuator(Stream<char> *stream);

    std::optional<Token> consume_keyword(Stream<char> *stream);

    std::optional<Token> consume_identifier(Stream<char> *stream);

    /**
     * @brief Consumes a literal from the stream.
     *
     * Here we're mainly concerned about the following:
     * - strings
     * - numbers
     * - chars
     *
     * Keep in mind these values aren't actually parsed, just identified.
     */
    std::optional<Token> consume_literal(Stream<char> *stream);

    /**
     * @brief A reserved value is either one that:
     * - is a reserved keyword.
     * - used in the language as semantic meaning.
     *
     * @param stream
     * @return std::optional<Token>
     */
    std::optional<Token> consume_reserved(Stream<char> *stream);
}

#endif