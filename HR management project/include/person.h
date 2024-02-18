#ifndef PERSON_H
#define PERSON_H
#include <bits/stdc++.h>
#include "customers.h"
using namespace std;

class person : public customers
{
private:
    string address;
    string name;
public:
    person();
    void setaddress(string);
    void setname(string);
    string getaddress();
    string getname();
    void getinfo();
    void print ();
    virtual ~person();

};

#endif // PERSON_H
