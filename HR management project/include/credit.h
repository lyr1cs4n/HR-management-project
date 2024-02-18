#ifndef CREDIT_H
#define CREDIT_H

#include "payment.h"
using namespace std;

class credit :public payment
{
    private:
        string number;
        string expire_date;
        string type;
    public:
        credit();
        void getinfo ();
        void print ();
        void setnumber(string);
        void setexpire_date(string);
        void settype(string);
        string getnumber();
        string getexpire_date();
        string gettype();
        virtual ~credit();

};

#endif // CREDIT_H
