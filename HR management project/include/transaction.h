#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "order.h"
#include "payment.h"
#include "credit.h"
#include "cash.h"
#include "check.h"
class transaction
{
    private:
        string t_date;
        payment ** transtype;
        order ** orderlist;
        int index;
        int order_size;
    public:
        transaction(order* orders,int numOrders);
        void check_payment();
        void getorder();
        void printTransactions();
        virtual ~transaction();

};

#endif // TRANSACTION_H
