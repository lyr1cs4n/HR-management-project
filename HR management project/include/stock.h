#ifndef STOCK_H
#define STOCK_H
#include "product.h"

class stock
{
private:
    int stock_count;
    int stock_size;
    product * prodlist;
public:
    stock(int);
    void addstock();
    void updatestock();
    void deleteprod();
    void print();
    void searchcus(string data, int key);
    void getquantity();
    int getProductCount();
    product* getproduct(int) ;
    void decProdQty();
    void incrementProductQuantityBy(int index, int quantity );
    int getProductCount() const;
    void decrementProductQuantityBy(int index, int quantity );
    void incrementProductQuantity(int index);
    bool getprodid(int x);
    int getindex(int x);
    void decrementProductQuantity(int index);
    product* getProduct(int index) const;
    double getprodinfo(int x);
    int getStock_count();
    virtual ~stock();

};

#endif // STOCK_H
