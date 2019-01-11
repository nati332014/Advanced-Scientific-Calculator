
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

#include "txtParser.h"

txtParser::txtParser()
{
}
std::vector<string> txtParser::stateChk(string strPost)
{
    vector<string> strTok;
    char currChar = ' ';
    int col = NONE;
    int currentState = NONE;
    string currToken = "";

    // use an FSM to parse multidigit and decimal numbers
    // also does error check for invalid input of decimals
    for(unsigned x = 0; x < strPost.length();)
    {
        currChar = strPost[x];

        // get the column number for the current character
        col = getStates(currChar);

        // exit if the real number has multiple periods "."
        // in the expression (i.e: 19.3427.23)
        if((currentState == DEC) && (col == DEC))
        {
            cerr<<"\nINVALID INPUT #2\n";
            exit(1);
        }
        /* ========================================================

            THIS IS WHERE WE CHECK THE FINITE STATE MACHINE TABLE
               USING THE "col" VARIABLE FROM ABOVE ^

          ========================================================= */

        // get the current state of our machine
        currentState = finiteTable[currentState][col];

        if(currentState == NONE)
        {
            if(currToken != " ") // we dont care about whitespace
            {
                strTok.push_back(currToken);
            }
            currToken = "";
        }
        else
        {
            currToken += currChar;
            ++x;
        }
    }

    if(currToken != " ") // we dont care about whitespace
    {
        strTok.push_back(currToken);
    }
    return strTok;
}// end of Lexer

int txtParser::getStates(char& currChar)
{// this function determines the state of the type of character being examined
    // check for whitespace
    if(isspace(currChar))
    {
        return BLANK;
    }

    // check for integer numbers
    else if(isdigit(currChar))
    {
        return NUM;
    }

    // check for real numbers
    else if(currChar == '.')
    {
        return DEC;
    }

    // check for negative numbers
    else if(currChar == '~')
    {
        currChar = '-';
        return NEG;
    }

    // check for math operators
    else if(isOperator(currChar))
    {
        return OPR;
    }
    return UNDIF;
}// end of Get_FSM_Co
