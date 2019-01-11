#ifndef POSTFIXEXPRESSION_H
#define POSTFIXEXPRESSION_H

#include "tokenizer.h"

class postfixExpression: public tokenizer{

    public:
        postfixExpression();

        std::string infixToPostfix(std::string infix);
        int precedence(char token);

    protected:

    private:
};

#endif // POSTFIXEXPRESSION_H
