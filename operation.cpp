
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

#include "operation.h"

operation::operation()
{
}
double operation::evalPost(const vector<string>& postfix)
{
    double op1 = 0;
    double op2 = 0;
    double answer = 0;
    stack<double> doubleStack;

    // loop thru array until there is no more data
    for(unsigned x = 0; x < postfix.size(); ++x)
    {
        // push numbers onto the stack
        if((isdigit(postfix[x][0])) || (postfix[x][0] == '.'))
        {
           doubleStack.push(atof(postfix[x].c_str()));
        }
        // push negative numbers onto the stack
        else if((postfix[x].length() > 1) && ((postfix[x][0] == '-') &&
            (isdigit(postfix[x][1]) || (postfix[x][1] == '.'))))
        {
           doubleStack.push(atof(postfix[x].c_str()));
        }
        // if expression is a math operator, pop numbers from stack
        // & send the popped numbers to the 'Calculate' function
        else if(isOperator(postfix[x][0]) && (!doubleStack.empty()))
        {
            char token = tolower(postfix[x][0]);

            // if expression is square root, sin, cos,
            // or tan operation only pop stack once
            if(token == '$' || token == 's' || token == 'c' || token == 't')
            {
                op2 = 0;
                op1 = doubleStack.top();
                doubleStack.pop();
                answer = calc(token, op1, op2);
                doubleStack.push(answer);
            }
            else if(doubleStack.size() > 1)
            {
                op2 = doubleStack.top();
                doubleStack.pop();
                op1 = doubleStack.top();
                doubleStack.pop();
                answer = calc(token, op1, op2);
                doubleStack.push(answer);
            }
        }
        else // this should never execute, & if it does, something went really wrong
        {
           cout<<"\nINVALID INPUT #3\n";
           exit(1);
        }
    }
    // pop the final answer from the stack, and return to main
    if(!doubleStack.empty())
    {
        answer = doubleStack.top();
    }
    return answer;
}// end of EvaluatePostfix

double operation::calc(char token, double op1, double op2)
{
    double ans = 0;
    switch(tolower(token))
    {
        case '+':

           ans = op1 + op2;
           break;
        case '-':

           ans = op1 - op2;
           break;
        case '*':

           ans = op1 * op2;
           break;
        case '/':
if(op2==0) { ans=-1; }
  else
        ans = op1 / op2;

           break;
        case '%':

           ans = ((int)op1%(int)op2)+modf(op1 , &op2);
           break;
        case '^':

           ans = pow(op1, op2);
           break;
        case '$':

           ans = sqrt(op1);
           break;
        case 'c':
             if(op1==90)
                {
                    ans = round(cos(op1*(pi/180)));
                }
             else{
                    ans = cos(op1*(pi/180));
                 }
            break;
        case 's':

            ans = sin(op1*(pi/180));
            break;
        case 't':

            ans = tan(op1*(pi/180));
            break;
        default:
           ans = 0;
           break;
    }

    return ans;
}


