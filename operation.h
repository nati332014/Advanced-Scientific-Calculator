
#ifndef OPERATION_H
#define OPERATION_H
#include "tokenizer.h"

class operation : public tokenizer{
    public:
        operation();
        double const pi=3.1415926535897932384626433832795;

        double evalPost(const std::vector<std::string>& postfix);
        double calc(char token, double op1, double op2);

    protected:

    private:
};

#endif // OPERATION_H
