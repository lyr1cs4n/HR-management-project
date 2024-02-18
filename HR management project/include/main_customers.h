#ifndef MAIN_CUSTOMERS_H
#define MAIN_CUSTOMERS_H
#include <bits/stdc++.h>
#include "person.h"
#include "customers.h"
#include "company.h"
using namespace std;

class main_customers
{
private:
    int cus_count;
    int cus_size;
    customers **cuslist;
public:
    main_customers(int);
    void addcustomers();
    void editcustomers();
    void deletecustomers();
    void print();
    void mainscreen(int key);
    void searchcus();
    bool  checkid(int id);
    int getCus_count();
    customers* getcus(int id);
    virtual ~main_customers();
};

#endif // MAIN_CUSTOMERS_H
