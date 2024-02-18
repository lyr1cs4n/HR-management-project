#ifndef PAYMENT_H
#define PAYMENT_H
#include <bits/stdc++.h>
using namespace std;
class payment
{
    private:
        string date;
        double amount;
    public:
        payment();
        virtual void getinfo();
        virtual void print ();
        void setamount (double);
        double getamount ();
        string getdate();
        virtual ~payment();

};

#endif // PAYMENT_H
