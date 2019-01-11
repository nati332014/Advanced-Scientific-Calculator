

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

#include "stringFilter.h"
#include "postfixExpression.h"
#include "operation.h"
#include "trigFunction.h"
#include "decimalConverter.h"

#include "tokenizer.h"

using namespace std;

stringFilter::stringFilter()
{
}

//========================================= second class ================================================================

string stringFilter::finalFilter(vector <string> subexp)
{
    txtParser tok;
    postfixExpression pfix;
    operation opr;
    trigFunction trig;
    decimalConverter dec_con;

    vector <string> vText;
    vector <string> var;
    vector <string> num;
    vector <string> exp_v;
    string stemp;
    string final_concat;
    string input4;
    string left1;
    string right1;
    string exp_sec;
    string strf;
    string s1;

    string convt_to_str;
    ostringstream tempo;

string infix = "";
    string postfix = "";
    double answer = 0;
    vector<string> tokens;
int glob=0;
string input;

      for(int l=0;l<subexp.size();l++)
        {
                input =subexp[l];
                for(int j=0;j<input.length();j++)
                {
                    if(input[j]== '=')
                    {
                        glob=1;
                    }
                }
            }

            if(glob==0)
                {
                        again1:
                        for(unsigned i=0; i<input.length();i++)
                            {
                                if(tolower(input[i])=='b')
                                    {
                                        input=dec_con.binary_filter(input, i);
                                        goto again1;
                                    }
                            }

                        bgin:
                        for(unsigned i=0; i<input.length();i++)
                            {
                                if(input[i]=='0' && tolower(input[i+1])=='x' )
                                    {
                                        input=dec_con.hexfilter(input, i);
                                        goto bgin;
                                    }
                            }

                        bg:
                        for(int i=0;i<input.length();i++)
                            {


                                if(tolower(input[i])=='s' && tolower(input[i+1])=='i' && tolower(input[i+2])=='n' && input[i+3]=='(')
                                    {
                                        input=trig.sin_filter(input,i);
                                        goto bg;
                                    }
                                else if(tolower(input[i])=='c' && tolower(input[i+1])=='o' && tolower(input[i+2])=='s' && input[i+3]=='(')
                                    {
                                        input=trig.cos_filter(input,i);
                                        goto bg;
                                    }
                            }
                                //cout<<"\n \n After Binary , cosine and sine filtered -----> "<<input<<"\n\n\n";
                               postfix = pfix.infixToPostfix(input);
            if(postfix=="-2")  {
		   convt_to_str="ERROR! Parenthesis mismatch";
		    return convt_to_str;
	           }
	            else if(postfix=="-3")  {
                    convt_to_str="ERROR! Invalid input";
                    return convt_to_str;
                    }
	           else
	              tokens = tok.stateChk(postfix);
                 answer = opr.evalPost(tokens);
            if(answer==-1)  {
		   convt_to_str="ERROR! Division by zero";
		    return convt_to_str;
	           }
           else{
    tempo<<answer;
    convt_to_str=tempo.str();
	                     return convt_to_str;
                    }
                    }

                else if(glob==1)
                    {
                            for(int j=0;j<subexp.size();j++)
                                {
                            stemp=subexp[j];


                            for(int j=0;j<stemp.length();j++){
                            if(stemp[j]== '=')
                                {
                            left1=leftExp(stemp,j);
                            right1=rightExp(stemp,j);
                            var.push_back(left1);
                            num.push_back(right1);

                            }
                            exp_sec=stemp;
                            }
                            }
                             s1 = exp_sec;
                                    string tempV;
                                    for (int i = 0; i  < s1.length(); i++)
                                    {
                                        char c = s1[i];
                                        string ss;
                                        ss.push_back(c);
                                    switch(c)
                                        {
                                            case '+': case '-':  case '*': case '/':   case '(':  case ')': case '^':
                                                    vText.push_back(ss);
                                                break;
                                                default:
                                                    while((int(s1[i])>=65 && int(s1[i])<=90)|| (int(s1[i])>=97 && int(s1[i])<=122) || (int(s1[i])>=48 && int(s1[i])<=57))
                                                        {
                                                            tempV += s1[i];
                                                            i=i+1;
                                                            if(s1[i]=='+' || s1[i]=='-' || s1[i]=='*' || s1[i]=='/' || s1[i]=='(' || s1[i]==')' || s1[i]=='^')
                                                            break;
                                                        }
                                                    if (tempV.length() > 0)
                                                    {
                                                        vText.push_back(tempV);
                                                        tempV = "";
                                                        i--;
                                                    }
                                                break;
                                        }
                                    }

                            for(int k=0;k<vText.size();k++)
                                {
                                  for(int l=0;l<var.size();l++)
                                    {
                                      if(vText[k]==var[l])
                                         {
                                          vText[k]=num[l];
                                         }
                                    }
                                }

                            for(int m=0;m<vText.size();m++){
                               final_concat+= vText[m];

                            }

                                string input="";

                              input=final_concat;

                            sec2_again:
                                for(unsigned i=0; i<input.length();i++){
                                    if(tolower(input[i])=='b')
                                    {
                                        input=dec_con.binary_filter(input, i);
                                       goto sec2_again;
                                    }
                                }
                                sec2_bgin:
                                for(unsigned i=0; i<input.length();i++){
                                    if(input[i]=='0' && tolower(input[i+1])=='x' )
                                    {
                                        input=dec_con.hexfilter(input, i);
                                        goto sec2_bgin;
                                    }
                                }

                            sec2_bg:
                                for(int i=0;i<input.length();i++)
                              {
                                  if(tolower(input[i])=='s' && tolower(input[i+1])=='i' && tolower(input[i+2])=='n' && input[i+3]=='(')
                                     {
                                         input=trig.sin_filter(input,i);

                                         goto sec2_bg;
                                     }
                                    else if(tolower(input[i])=='c' && tolower(input[i+1])=='o' && tolower(input[i+2])=='s' && input[i+3]=='(')
                                     {

                                         input=trig.cos_filter(input,i);
                                         goto sec2_bg;
                                      }
                                  }

                                  postfix = pfix.infixToPostfix(input);
                                   if(postfix=="-2")  {
                                       convt_to_str="ERROR! Parenthesis mismatch";
                                        return convt_to_str;
                                           }
                                        else if(postfix=="-3")  {
                                          convt_to_str="ERROR! Invalid input";
                                          return convt_to_str;
                                           }
                                           else
                                              tokens = tok.stateChk(postfix);

                                  answer = opr.evalPost(tokens);
                                     if(answer==-1)  {
                                       convt_to_str="ERROR! Division by zero";
                                        return convt_to_str;
                                           }
                                       else{
                            tempo<<answer;
                                convt_to_str=tempo.str();

                                return convt_to_str;
    }}
}

 string stringFilter::leftExp(string input4,int i){
  string fr;
for(int j=0;j<i;j++)
    {
       // cout<<"input"<<input[j]<<endl;
        fr+=input4[j];
    }
return fr;
}

string stringFilter::rightExp(string input4,int i){

  string sc;

   for(int k=i+1;k<input4.length();k++)
        sc+=input4[k];

return sc;
}


