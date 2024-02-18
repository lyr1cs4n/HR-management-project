#include "transaction.h"

transaction::transaction(order* orders, int numOrders)
{
    t_date = __DATE__;
    orderlist = new order*[numOrders];
    for (int i = 0; i < numOrders; i++)
    {
        orderlist[i] = &orders[i];
    }
    order_size = numOrders;
    transtype = new payment*[numOrders];
    index = 0;
}
void transaction::printTransactions()
{
    cout << "Transactions:" << endl<<endl;
    for (int i = 0; i < index; i++)
    {
        cout << "Transaction " << i + 1 << ":" << endl;
        orderlist[i]->print();
        transtype[i]->print();
        cout << endl;
    }
}
void transaction::getorder()
{
    bool check1 = false;
    for (int i = 0; i < 50; i++)
    {
        if (orderlist[i]->getorder_count() != 0)
        {
            check1 = true;
            break;
        }
    }

    if (check1)
    {
        int id;
        cout << "Enter The ID Of The Order: ";
        cin >> id;
        bool check2= false;
        for (int i = 0; i < order_size; i++)
        {
            if (orderlist[i]->getid() == id)
            {
                orderlist[i]->print();
                cout << "Do You Want To Checkout [y/n]: ";
                string s;
                cin >> s;

                if (s == "y" || s == "Y")
                {
                    cout << "Choose Your Payment [Credit - Cash - Check]: ";
                    string x;
                    cin >> x;

                    if (x == "Credit" || x == "credit")
                    {
                        transtype[index] = new credit();
                        transtype[index]->getinfo();

                        if (transtype[index]->getamount() >= orderlist[i]->getprodprice())
                        {
                            cout << "    Transaction Complete.";
                            orderlist[i]->setstate("Paid");
                            index++;
                        }
                        else
                        {
                            cout << "    Transaction Failed (Not Enough Cash)";
                            transtype[index] = nullptr;
                        }
                    }
                    else if (x == "Cash" || x == "cash")
                    {
                        transtype[index] = new cash();
                        transtype[index]->getinfo();

                        if (transtype[index]->getamount() >= orderlist[i]->getprodprice())
                        {
                            cout << "    Transaction Complete.";
                            orderlist[i]->setstate("Paid");
                            index++;
                        }
                        else
                        {
                            cout << "    Transaction Failed (Not Enough Cash)";
                            transtype[index] = nullptr;
                        }
                    }
                    else if (x == "Check" || x == "check")
                    {
                        transtype[index] = new check();
                        transtype[index]->getinfo();

                        if (transtype[index]->getamount() >= orderlist[i]->getprodprice())
                        {
                            cout << "    Transaction Complete.";
                            orderlist[i]->setstate("Paid");
                            index++;
                        }
                        else
                        {
                            cout << "    Transaction Failed (Not Enough Cash)";
                            transtype[index] = nullptr;
                        }
                    }
                }
                check2 =true;
                break;
            }
        }
         if(!check2){
            cout<<"ID not found";
        }
    }
    else
    {
        cout << "No orders available." << endl;
    }
}

transaction::~transaction()
{
     delete[] orderlist;
}
