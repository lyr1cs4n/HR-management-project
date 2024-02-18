#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include <bits/stdc++.h>
using namespace std;

class customers
{
private:
    int id;
    string phone;
public:
    customers();
    virtual void print();
    virtual void getinfo();
    virtual string getname()=0;
    void setphone(string x);
    void setid(int x);
    int getid();
    string getphone();
    virtual ~customers();

};
#endif
