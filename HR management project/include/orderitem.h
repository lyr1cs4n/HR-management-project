#ifndef ORDERITEM_H
#define ORDERITEM_H
#include "stock.h"

class orderitem
{
    private:
        int productIndex;
        double sale_price;
        int quantity;
        stock * stocklist;
    public:
        orderitem();
        orderitem(stock* stockObj,int index);
        void setsaleprice();
        double getsaleprice();
        void checkitem(int qty);
        virtual ~orderitem();
        orderitem& operator++();
        orderitem& operator--();
        orderitem& operator+=(int);
        orderitem& operator-=(int);
};

#endif // ORDERITEM_H
