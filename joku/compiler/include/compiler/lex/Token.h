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
            COLON = 2,
            /**
             * @brief A token that represents a reserved word.
             * EG: `var` in `var x = 1;`
             */
            KEYWORD = 3,
            /**
             * @brief A token that represents a variable or label.
             * EG: `x` in `var x = 1;`
             */
            IDENTIFIER = 4,
            /**
             * @brief A token that represents a literal char.
             * EG: `1` in `var x = '1';`
             */
            LITERAL_CHAR = 5,
            /**
             * @brief A token that represents an operator.
             * EG: `+` in `var x = 1 + 2;`
             */
            LITERAL_STRING = 6,
            /**
             * @brief A token that represents a literal number or integer.
             */
            LITERAL_NUMBER = 7,
            /**
             * @brief A specific character that specifies an operation.
             * EG: `+` in `var x = 1 + 1;`
             */
            OPERATOR,
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