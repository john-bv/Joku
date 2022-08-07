#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <vector>

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
     * @brief A token that represents a literal, otherwise known as
     * something that can be saved on stack.
     * EG: `1` in `var x = 1;`
     */
    LITERAL = 5,
    /**
     * @brief A specific character that specifies an operation.
     * EG: `+` in `var x = 1 + 1;`
     */
    OPERATOR = 6,
    /**
     * @brief A specific character that is not specifically related to a operation
     * but performs a specific action.
     * EG: `..` in `var x = 0..10;`
     */
    PUNCTUATOR = 7,
    /**
     * @brief Represents the end of a file.
     * Sometimes used in place to prevent errors.
     */
    END_OF_FILE = 8,
    /**
     * @brief Represents whitespace.
     */
    WHITESPACE = 9,
    /**
     * @brief Represents a comment. Specifically Inline or multiline.
     */
    COMMENT = 10,
    /**
     * @brief Represents a comment, one that is one line.
     */
    COMMENT_SINGLE = 11
};

class Token
{
    private:
        char *value;
        TokenVariant variant;
        int position;
        int *buffer;

    public:
        Token();

        Token(char *value, TokenVariant variant, int position = -1, int *buffer = nullptr);

        TokenVariant get_variant();
        void set_position(int position);

        bool is_null();

        int belongs_to();
};
#endif // TOKEN_H