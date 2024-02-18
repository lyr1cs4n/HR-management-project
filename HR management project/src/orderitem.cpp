#include "orderitem.h"
orderitem::orderitem()
{
}
orderitem::orderitem(stock* stockObj,int index)
{
    stocklist=stockObj;
    productIndex = index;
    sale_price = 0;
}
void orderitem::setsaleprice()
{
    sale_price=stocklist->getproduct(productIndex)->getprice() * 1.2;
}
double orderitem::getsaleprice()
{
    return sale_price;
}
orderitem& orderitem::operator++()
{
    ++quantity;
    stocklist->incrementProductQuantity(productIndex);
    return *this;
}

orderitem& orderitem::operator--()
{
    --quantity;
    stocklist->decrementProductQuantity(productIndex);
    return *this;
}

orderitem& orderitem::operator+=(int n)
{
    quantity += n;
    stocklist->incrementProductQuantityBy(productIndex, n);
    return *this;
}

orderitem& orderitem::operator-=(int n)
{
    quantity -= n;
    stocklist->decrementProductQuantityBy(productIndex, n);
    return *this;
}
orderitem::~orderitem()
{

}
