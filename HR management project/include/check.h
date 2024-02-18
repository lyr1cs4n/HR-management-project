#ifndef CHECK_H
#define CHECK_H
#include "payment.h"
#include <strings.h>
using namespace std;
class check : public payment
{
    private:
        string name;
        string bank_id;
    public:
        check();
        void getinfo ();
        void print ();
        void setname(string);
        void setbank_id(string);
        string getname();
        string getbank_id();
        virtual ~check();

};

#endif // CHECK_H
