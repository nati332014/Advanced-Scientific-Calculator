
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

#include "trigFunction.h"

trigFunction::trigFunction()
{
    //ctor
}

string trigFunction::sin_filter(string input,int i){
   string fr;
   string sc;

for(int j=0;j<i;j++)
    {
        fr+=input[j];
    }
        fr+='s';fr+='(';
    for(int k=i+4;k<input.length();k++)
        sc+=input[k];

 input=fr+sc;
return input;
}

string trigFunction::cos_filter(string input,int i){
  string fr;
  string sc;

for(int j=0;j<i;j++)
    {
        fr+=input[j];
    }
        fr+='c';fr+='(';
   for(int k=i+4;k<input.length();k++)
        sc+=input[k];

 input=fr+sc;

return input;
}

