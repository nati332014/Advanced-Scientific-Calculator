#ifndef IOFILESTRM_H
#define IOFILESTRM_H

using namespace std;
class ioFilestrm
{
    public:
        ioFilestrm();
        string strf;
        vector <string> exp;
        vector <string> final_result;
        void reader();
        void writer();


    protected:

    private:
};

#endif // IOFILESTRM_H
