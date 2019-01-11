
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

#include "ioFilestrm.h"
#include "stringFilter.h"

ioFilestrm::ioFilestrm()
{
}
void ioFilestrm::reader()
              {
                ifstream infile("inputFileName.txt");
                if(!infile){
                        cout<<endl <<endl;
                    cout<< "file not found or Invalid file name"<<endl<<endl;
                }
            //
                 else{
                final_result.push_back("----");
                 cout<<endl;
                 cout<<"The output file name is: outputFileName.txt"<<endl;
                     cout<<endl;
                while(!infile.eof())
                    {
                        getline(infile,strf);
                        exp.push_back(strf);
                    }
                }
              }

         void ioFilestrm::writer()
                {
                    stringFilter fileWriter;
                       ofstream outfil("outputFileName.txt");
                        string temp;
                        vector <string> subexp;
                        string final_result1;

                        for(int k=1;k<exp.size();k++)
                        {
                            temp=exp[k];

                            if(temp[0] != '-')
                            {
                                subexp.push_back(exp[k]);
                            }
                            else if (temp[0] =='-')
                            {
                                final_result1=fileWriter.finalFilter(subexp);
                                final_result.push_back(final_result1);
                                final_result.push_back("----");
                                subexp.clear();
                            }
                        }

                            for(int n=0;n<final_result.size();n++)
                                {
                                    cout<<final_result[n]<<endl;
                                }
                            if (outfil.is_open())
                                {
                                    for(int n=0;n<final_result.size();n++)
                                        {
                                            outfil<<final_result[n]<<endl;
                                        }
                                    outfil.close();
                                }}







