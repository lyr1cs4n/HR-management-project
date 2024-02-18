#ifndef CASH_H
#define CASH_H
#include "payment.h"

class cash : public payment
{
private:
        double cashValue;
    public:
        cash();
        void getinfo();
        void print ();
        void setcash(double x);
        double getcash ();
        virtual ~cash();
};

#endif // CASH_H
