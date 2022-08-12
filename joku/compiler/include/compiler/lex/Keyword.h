#ifndef __KEYWORD_H__
#define __KEYWORD_H__

#include <optional>
#include <array>
#include <string>

namespace joku::compiler::lexer::kw
{
    const int MAX_KEYWORD_LENGTH = 10;

    enum Keyword
    {
        ABSTRACT = 0,
        ASM,
        AWAIT,
        ASYNC,
        AS,
        BECOME,
        BREAK,
        CASE,
        CATCH,
        CLASS,
        CONST,
        CONTINUE,
        DATA,
        DELETE,
        DO,
        ELSE,
        ENUM,
        EXPORT,
        EXTENDS,
        EXTERN,
        FALSE,
        FINAL,
        FOR,
        FROM,
        FN,
        IF,
        IMPORT,
        IN,
        IS,
        LET,
        LOOP,
        MATCH,
        MOD,
        OF,
        PRIV,
        PUB,
        PROT,
        RETURN,
        SELF,
        STATIC,
        SUPER,
        TRUE,
        TRAIT,
        TRY,
        TYPE,
        THROW,
        TYPEOF,
        VAR,
        WHERE,
        WHILE,
        YIELD
    };

    std::optional<Keyword> keyword_from_str(std::string *keyword);
}

#endif