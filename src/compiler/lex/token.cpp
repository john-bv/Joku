#include <vector>
#include "lex/token.h"

enum TokenVariant: unsigned char {
    /**
     * @brief A token that represents something that can not change.
     * EG: `var` in `var x = 1;`
     */
    CONSTANT,
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
     * @brief A token that represents a literal, otherwise known as
     * something that can be saved on stack.
     * EG: `1` in `var x = 1;`
     */
    LITERAL,
    /**
     * @brief A specific character that specifies an operation.
     * EG: `+` in `var x = 1 + 1;`
     */
    OPERATOR,
    /**
     * @brief A specific character that is not specifically related to a operation
     * but performs a specific action.
     * EG: `..` in `var x = 0..10;`
     */
    PUNCTUATOR,
    /**
     * @brief Represents the end of a file.
     * Sometimes used in place to prevent errors.
     */
    END_OF_FILE,
};

class Token {
private:
    char* value;
    TokenVariant variant;
    int position;
    // this can be null!
    int buffer_id;

public:
    Token(char* value, TokenVariant variant, int position = -1, int buffer_id = 0);
    ~Token();

    TokenVariant get_variant() {
        return this.variant;
    }

    void set_position(int position) {
        this.position = position;
    }

    int belongs_to() {
        return this.buffer_id || 0;
    }
};

class TokenBuffer {
private:
    Token* tokens;
    Token previous_token;
    int id;
    int current_position;
    /**
     * @brief Whether or not to consume tokens when calling next_token().
     */
    bool consume;

    Token increment() {
        if ((this.current_position + 1) >= this.tokens.size()) {
            return nullptr;
        } else {
            return this.tokens[this.current_position++];
        }
    }

    bool available(int pos = current_position + 1) {
        return pos < this.tokens.size();
    }

public:
    TokenBuffer(int id);
    ~TokenBuffer() {
        delete[] this.tokens;
    }

    /**
     * @brief Get the next token object, but does not increment the position.
     * @return Token
     */
    Token get_next() {
        if (this.available()) {
            return this.tokens[this.current_position + 1];
        } else {
            return nullptr;
        }
    }

    /**
     * @brief Get the next token object
     * @return Token
     */
    Token get_current() {
        return this.tokens[this.current_position];
    }

    /**
     * @brief Get the previous token object
     * @return Token
     */
    Token get_previous() {
        return this.previous_token;
    }

    Token get_at(int position) {
        if (position > this.tokens.size()) {
            return nullptr;
        }

        return this.tokens[position];
    }

    void push(Token token) {
        &token.set_position(this.tokens.size());
        this.tokens[this.tokens.size()] = token;
    }

    int size() {
        return this.tokens.size();
    }

    int get_id() {
        return this.id;
    }

    int get_position() {
        return this.current_position;
    }
};