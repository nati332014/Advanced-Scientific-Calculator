#ifndef TRIGFUNCTION_H
#define TRIGFUNCTION_H

#include "stringFilter.h"

class trigFunction :public stringFilter
{
    public:
        trigFunction();

std::string sin_filter(std::string str, int i);
std::string cos_filter(std::string str, int i);

    protected:

    private:
};

#endif // TRIGFUNCTION_H
