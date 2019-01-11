
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

#include "decimalConverter.h"

decimalConverter::decimalConverter()
{
    //ctor
}
string decimalConverter::binary_filter(string infix,int i)
{
    string s="";
    string fr3;
    string sc3;
       int a=i-1;
            while(true)
            {
                if(isdigit(infix[a]) || isBinChar(infix[a]))
                {
                    s+=infix[a];
                    a--;
                }
                else{
                    //cout<<"invalid hexadecimal input"<<endl;
                    break;
                }
            }

   reverse(s.begin(),s.end());

//string  to integer converstion   name is converted to n long integer
//==============================
   long long n;
  stringstream geek(s);
  geek>>n;

//binary To decimal Converstion
//==============================
  int dec = 0;
  int rem;
  int l = 0;
  while(n!=0)
    {
    rem=n%10;
    n/=10;
    dec+=rem*pow(2,l);
    ++l;
    }
  int ans= dec;
    string strr;
    ostringstream temp;
    temp<<ans;
    strr=temp.str();
       for(int j=0;j<=a;j++)
            fr3+=infix[j];


            for(int k=i+1;k<infix.length();k++)
             sc3+=infix[k];

            infix=fr3+strr+sc3;
         // cout<<"The final string is:   " <<infix<<endl;
          return infix;
    }

bool decimalConverter::isBinChar(char c){
if ( c =='1' || c == '0'){

    return true;
    }
else{
    return false;
}
}

string decimalConverter::hexfilter(string infix,int i)
{
    string s="";
    string fr3;
    string sc3;
       int a=i+2;
            while(true)
            {
                if(isdigit(infix[a]) || ishexaChar(infix[a]))
                {
                    s+=infix[a];
                    a++;
                }
                else{
                    break;
                }
            }
           unsigned int x;
stringstream ss;
ss << hex << s;
ss >> x;
string Result;

ostringstream convert;

convert << x;

Result = convert.str();
//cout << static_cast<int>(x)<<endl;

       for(int j=0;j<i;j++)
            fr3+=infix[j];

            for(int k=a;k<infix.length();k++)
             sc3+=infix[k];
            //cout<<"The second string is:   " <<sc3<<endl;
            fr3+=Result;

            infix=fr3+sc3;
         // cout<<"The final string is:   " <<infix<<endl;
          return infix;
   }

bool decimalConverter::ishexaChar(char c){
if ( toupper(c)>='A' && toupper(c)<= 'F'){
    return true;
    }
else{
    return false;
}
}





