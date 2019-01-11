#ifndef STRINGFILTER_H
#define STRINGFILTER_H

#include "txtParser.h"

class stringFilter
{
    public:
        stringFilter();
std::string finalFilter(std::vector <std::string> subexp);


//===========================================================================

    protected:

    private:
        std::string leftExp(std::string input4,int i);
        std::string rightExp(std::string input4,int i);
};

#endif // STRINGFILTER_H
