#ifndef TOKEN_H
#define TOKEN_H
#include <vector>

enum TokenVariant: unsigned char {
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
     * @brief Represents a comment. Specifically Inline or multiline.
     */
    COMMENT = 9,
    /**
     * @brief Represents a comment, one that is one line.
     */
    COMMENT_SINGLE = 10
};

class Token {
private:
    char* value;
    TokenVariant variant;
    int position;
    TokenBuffer *buffer;
public:
    Token();

    Token(char* value, TokenVariant variant, int position = -1, TokenBuffer *buffer = nullptr);

    TokenVariant get_variant();
    void set_position(int position);

    bool is_null();

    int belongs_to();
};

class TokenBuffer {
private:
    std::vector<Token> tokens;
    Token previous_token;
    int current_position;
    /**
     * @brief Whether or not to consume tokens when calling next_token().
     */
    bool consume = false;

    Token increment() {
        if ((current_position + 1) >= tokens.size()) {
            return Token();
        } else {
            return tokens[current_position++];
        }
    }

    bool available(int pos = 0) {
        return pos < tokens.size();
    }
public:
    TokenBuffer();
    ~TokenBuffer();

    /**
     * @brief Get the next token object, but does not increment the position.
     * @return Token
     */
    Token get_next();

    /**
     * @brief Get the next token object
     * @return Token
     */
    Token get_current();

    /**
     * @brief Get the previous token object
     * @return Token
     */
    Token get_previous();

    Token get_at(int position);

    void push(Token *token);

    int size();

    int get_position();
};
#endif // TOKEN_H