#ifndef PRODUCT_H
#define PRODUCT_H
#include <bits/stdc++.h>
using namespace std;

class product
{
private:
    int id;
    string number;
    string name;
    double price;
    int quantity;
    int type;
public:
    product();
    void setnum(string);
    void setname(string);
    void setprice(double);
    void settype(int);
    void printorder();
    void setid(int);
    string getnum();
    string getname();
    double getprice();
    int getquantity();
    void setquantity(int x);
    void incrementbyquantity(int);
    void incrementquantity();
    void decrementbyquantity(int);
    void decrementquantity();
    int gettype();
    int getid();
    void getinfo();
    void print();
    virtual ~product();

};

#endif // PRODUCT_H
