#ifndef ORDER_H
#define ORDER_H
#include "stock.h"
#include "orderitem.h"
#include "product.h"
#include "main_customers.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <iostream>
#include <bits/stdc++.h>
class order
{
    private:
        int order_size;
        int order_count;
        int id;
        int number;
        double amount;
        string date;
        int total;
        string orderStatus;
        stock * stockobj;
        orderitem ** orderlist;
        product** prodlist;
        main_customers* cuslist;
        customers * cuslocallist;
    public:
        order();
        order(int,stock* stocks, main_customers* cus);
        void createorder();
        void print ();
        void setid (int);
        int getid();
        void setstate(string x);
        void updateorder();
        void editorder();
        int getorder_count();
        double getprodprice();
        virtual ~order();
};

#endif // ORDER_H
