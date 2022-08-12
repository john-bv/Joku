#include "compiler/lex/Keyword.h"

using namespace joku::compiler::lexer::kw;

// I strongly advise against looking at this file, it's messy.
std::optional<Keyword> joku::compiler::lexer::kw::keyword_from_str(std::string *kww)
{
    std::string keyword = *kww;

    if (keyword == "abstract")
    {
        return Keyword::ABSTRACT;
    }
    else if (keyword == "asm")
    {
        return Keyword::ASM;
    }
    else if (keyword == "async")
    {
        return Keyword::ASYNC;
    }
    else if (keyword == "await")
    {
        return Keyword::AWAIT;
    }
    else if (keyword == "as")
    {
        return Keyword::AS;
    }
    else if (keyword == "become")
    {
        return Keyword::BECOME;
    }
    else if (keyword == "break")
    {
        return Keyword::BREAK;
    }
    else if (keyword == "case")
    {
        return Keyword::CASE;
    }
    else if (keyword == "catch")
    {
        return Keyword::CATCH;
    }
    else if (keyword == "class")
    {
        return Keyword::CLASS;
    }
    else if (keyword == "const")
    {
        return Keyword::CONST;
    }
    else if (keyword == "continue")
    {
        return Keyword::CONTINUE;
    }
    else if (keyword == "data")
    {
        return Keyword::DATA;
    }
    else if (keyword == "delete")
    {
        return Keyword::DELETE;
    }
    else if (keyword == "do")
    {
        return Keyword::DO;
    }
    else if (keyword == "else")
    {
        return Keyword::ELSE;
    }
    else if (keyword == "enum")
    {
        return Keyword::ENUM;
    }
    else if (keyword == "export")
    {
        return Keyword::EXPORT;
    }
    else if (keyword == "extends")
    {
        return Keyword::EXTENDS;
    }
    else if (keyword == "extern")
    {
        return Keyword::EXTERN;
    }
    else if (keyword == "false")
    {
        return Keyword::FALSE;
    }
    else if (keyword == "final")
    {
        return Keyword::FINAL;
    }
    else if (keyword == "for")
    {
        return Keyword::FOR;
    }
    else if (keyword == "from")
    {
        return Keyword::FROM;
    }
    else if (keyword == "fn")
    {
        return Keyword::FN;
    }
    else if (keyword == "function")
    {
        return Keyword::FN;
    }
    else if (keyword == "if")
    {
        return Keyword::IF;
    }
    else if (keyword == "import")
    {
        return Keyword::IMPORT;
    }
    else if (keyword == "in")
    {
        return Keyword::IN;
    }
    else if (keyword == "is")
    {
        return Keyword::IS;
    }
    else if (keyword == "let")
    {
        return Keyword::LET;
    }
    else if (keyword == "loop")
    {
        return Keyword::LOOP;
    }
    else if (keyword == "match")
    {
        return Keyword::MATCH;
    }
    else if (keyword == "module")
    {
        return Keyword::MOD;
    }
    else if (keyword == "of")
    {
        return Keyword::OF;
    }
    else if (keyword == "priv")
    {
        return Keyword::PRIV;
    }
    else if (keyword == "pub")
    {
        return Keyword::PUB;
    }
    else if (keyword == "prot")
    {
        return Keyword::PROT;
    }
    else if (keyword == "return")
    {
        return Keyword::RETURN;
    }
    else if (keyword == "ret")
    {
        return Keyword::RETURN;
    }
    else if (keyword == "self")
    {
        return Keyword::SELF;
    }
    else if (keyword == "static")
    {
        return Keyword::STATIC;
    }
    else if (keyword == "super")
    {
        return Keyword::SUPER;
    }
    else if (keyword == "true")
    {
        return Keyword::TRUE;
    }
    else if (keyword == "trait")
    {
        return Keyword::TRAIT;
    }
    else if (keyword == "try")
    {
        return Keyword::TRY;
    }
    else if (keyword == "type")
    {
        return Keyword::TYPE;
    }
    else if (keyword == "throw")
    {
        return Keyword::THROW;
    }
    else if (keyword == "typeof")
    {
        return Keyword::TYPEOF;
    }
    else if (keyword == "var")
    {
        return Keyword::VAR;
    }
    else if (keyword == "where")
    {
        return Keyword::WHERE;
    }
    else if (keyword == "while")
    {
        return Keyword::WHILE;
    }
    else if (keyword == "yield")
    {
        return Keyword::YIELD;
    }
    else
    {
        return std::nullopt;
    }

}