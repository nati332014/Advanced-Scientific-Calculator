
#ifndef DECIMALCONVERTER_H
#define DECIMALCONVERTER_H

#include "stringFilter.h"
class decimalConverter
{
    public:
        decimalConverter();

        std::string binary_filter(std::string input,int i);
        std::string hexfilter(std::string input,int i);

    protected:

    private:
        bool  isBinChar(char c);
        bool ishexaChar(char c);

};

#endif // DECIMALCONVERTER_H
