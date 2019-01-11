
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

#include "postfixExpression.h"

postfixExpression::postfixExpression()
{
}

string postfixExpression::infixToPostfix(string infix)
{// this function converts an infix expression to postfix
    // declare function variables
    string postfix;
    stack<char> charStack;

    // loop thru array until there is no more data
    for(unsigned x = 0; x < infix.length(); ++x)
    {
        // place numbers (standard, decimal, & negative)
        // numbers onto the 'postfix' string
        if((isdigit(infix[x])) || (infix[x] == '.') || (infix[x] == '~'))
        {
            postfix += infix[x];
        }
        else if(isspace(infix[x]))
        {
            continue;
        }
        else if(isOperator(infix[x]))
        {
            postfix += " ";
            while((!charStack.empty()) &&
                (precedence(charStack.top()) >= precedence(infix[x])))
            {
                postfix += charStack.top();
                charStack.pop();
            }
            // push the remaining math operator onto the stack
            charStack.push(infix[x]);
        }
        // push outer parentheses onto stack
        else if(infix[x] == '(')
        {
            charStack.push(infix[x]);
        }
        else if(infix[x] == ')')
        {
            // pop the current math operator from the stack
            while((!charStack.empty()) && (charStack.top() != '('))
            {
                postfix += charStack.top();
                charStack.pop();
            }

            if(!charStack.empty()) // pop '(' symbol off the stack
            {
                charStack.pop();
            }
            else // no matching '('
            {
                goto parentMissMatch;
            }
        }
        else
        {
             goto invalidInput;
        }
    }

    while(!charStack.empty())
    {
        postfix += charStack.top();
        charStack.pop();
    }

    return postfix;
    parentMissMatch:
        return "-2";
        invalidInput:
         return "-3";
}
int postfixExpression::precedence(char token)
{// this function returns the priority of each math operator
    int priority = 0;
    switch(tolower(token))
    {
        case 'c': case 's': case 't':
           priority = 5;
           break;
        case '^': case '$':
           priority = 4;
           break;
        case '*': case '/': case '%':
           priority = 3;
           break;
        case '-':
           priority = 2;
           break;
        case '+':
           priority = 1;
           break;
    }
    return priority;
}// end of OrderOfOperations
