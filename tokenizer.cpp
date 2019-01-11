#include <vector>
#include<fstream>
#include <sstream>
#include <iostream>
#include <sstream>
#include<fstream>
#include <string>
#include <cmath>
#include <stack>
#include <algorithm>

#include "tokenizer.h"

using namespace std;

tokenizer::tokenizer()
{
}
bool tokenizer::isOperator(char token)
{// this function checks if operand is a math operator
    switch(tolower(token))
    {
        case '+': case '-': case '*': case '/':
        case '%': case '^': case '$': case 'c':
        case 's': case 't':
            return true;
            break;
        default:
           return false;
           break;
    }
}// end of IsMathOperator


