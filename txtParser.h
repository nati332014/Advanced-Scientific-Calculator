#ifndef TXTPARSER_H
#define TXTPARSER_H
#include "tokenizer.h"

using namespace std;
class txtParser : public tokenizer{
    public:
        txtParser();
        std::vector<std::string> stateChk(std::string strPost);
        int getStates(char& currentChar);

    protected:

    private:
};

#endif // TXTPARSER_H
