#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <vector>
#include <string>

namespace joku::compiler
{
    namespace TokenType
    {
        enum TokenVariant: unsigned char
        {
            /**
             * @brief A token that represents something that can not change.
             * EG: `var` in `var x = 1;`
             */
            CONSTANT = 1,
            /**
             * @brief A token that represents the end of a statement.
             * EG: `;` in `var x = 1;`
             */
            COLON,
            /**
             * @brief A token that represents a reserved word.
             * EG: `var` in `var x = 1;`
             */
            KEYWORD,
            /**
             * @brief A token that represents a variable or label.
             * EG: `x` in `var x = 1;`
             */
            IDENTIFIER,
            /**
             * @brief A token that represents a literal char.
             * EG: `1` in `var x = '1';`
             */
            LITERAL_CHAR,
            /**
             * @brief A token that represents an operator.
             * EG: `+` in `var x = 1 + 2;`
             */
            LITERAL_STRING,
            /**
             * @brief A token that represents a literal number (eg: int, double, char, etc).
             */
            LITERAL_NUMBER,
            /**
             * @brief An accessor token, which is used to access a member of an object or module.
             * EG: `.` in `var x = 1.0;`
             * EG: `::` in `var x = test::module`;
             */
            ACCESSOR,
            /**
             * @brief A token that represents a left bracket.
             * EG: `[` in `var x = {1, 2, 3};`
             */
            LEFT_BRACKET,
            /**
             * @brief A token that represents a right bracket.
             * EG: `]` in `var x = {1, 2, 3};`
             */
            RIGHT_BRACKET,
            /**
             * @brief A token that represents a left parenthesis.
             * EG: `(` in `var x = (1 + 2);`
             */
            LEFT_PAREN,
            /**
             * @brief A token that represents a right parenthesis.
             * EG: `)` in `var x = (1 + 2);`
             */
            RIGHT_PAREN,
            /**
             * @brief A token that represents a left brace.
             * EG: `{` in `var x = {1, 2, 3};`
             */
            LEFT_BRACE,
            /**
             * @brief A token that represents a right braces.
             * EG: `}` in `var x = {1, 2, 3};`
             */
            RIGHT_BRACE,
            /**
             * @brief A token that represents a statement end.
             * EG: `;` in `var x = 1;`
             */
            STATEMENT_END,
            /**
             * @brief A token that represents a comma.
             * EG: `,` in `var x = 1, 2, 3;`
             */
            COMMA,
            /**
             * @brief A token that represents a backslash.
             * EG: `\` in `var x = \SomeMoule();`
             */
            REVERSE_SLASH,
            /**
             * @brief A specific character that is not specifically related to a operation
             * but performs a specific action.
             * EG: `..` in `var x = 0..10;`
             * EG: `?` in match clause `var x = 0 ? 1 : 2;`
             */
            PUNCTUATOR,
            /**
             * @brief Represents the end of a file.
             * Sometimes used in place to prevent errors.
             */
            END_OF_FILE,
            /**
             * @brief Represents whitespace.
             */
            WHITESPACE,
            /**
             * @brief Represents a comment. Specifically Inline or multiline.
             */
            COMMENT,
            /**
             * @brief Represents a comment, one that is one line.
             */
            COMMENT_SINGLE,
            /**
             * @brief Unknown Token
             */
            UNKNOWN,
        };
    };

    class Token
    {
        private:
            std::string value;
            TokenType::TokenVariant variant;
            int start;
            int end;
            int *buffer;

        public:
            Token();

            Token(std::string value, TokenType::TokenVariant variant, int start = 0, int end = 0, int *buffer = nullptr);

            TokenType::TokenVariant get_variant();

            std::string get_name();

            std::string get_value()
            {
                return value;
            };

            void set_position(int position);

            bool is_null();

            int belongs_to();
    };
}
#endif // TOKEN_H