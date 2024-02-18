#ifndef COMPANY_H
#define COMPANY_H
#include "customers.h"
#include <bits/stdc++.h>
using namespace std;

class company : public customers
{
private:
    string location;
    string company_name;
public:
    company();
    void setlocation(string);
    void setcom_name(string);
    string getlocation();
    string getname();
    void getinfo();
    void print ();
    virtual ~company();

};

#endif // COMPANY_H
