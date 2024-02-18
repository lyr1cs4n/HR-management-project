#include "order.h"

order::order()
{

}
order::order(int size,stock* stocks, main_customers* cus)
{
    id = 0;
    order_size=size;
    order_count=0;
    number = rand() % 100000 + 1;
    date = __DATE__;
    total = 0.0;
    orderStatus = "new";
    stockobj = stocks;
    orderlist = new orderitem *[order_size];
    prodlist = new product *[100];
    cuslist = cus;

}
int order::getorder_count()
{
    return order_count;
}
double order::getprodprice()
{
    if(order_count==0)
    {
        return 0.0;
    }
    else
    {
        double sum=0;
        for (int i =0 ; i<order_count; i++)
        {
            sum+=orderlist[i]->getsaleprice();
        }
        return sum;
    }
}
void order::createorder() {
    if (cuslist->getCus_count() == 0) {
        cout << "[*] " << "\033[33mThere are no Customers in the database \033[0m" << endl << endl;
    } else {
        cout << "[*] " << "\033[33mEnter The ID Of The Customer: \033[0m";
        int id;
        cin >> id;
        bool check = false;
        do {
            if (cuslist->checkid(id)) {
                cuslocallist = cuslist->getcus(id);
                cout << endl;
                cuslocallist->print();
                cout << endl;
                cout << "[*] " << "\033[33mIs This The Customer ? [y/n] \033[0m";
                string t;
                cin >> t;
                if (t == "y" || t == "Y") {
                    if (stockobj->getStock_count() == 0) {
                        cout << endl;
                        cout << "    Stock Is Empty" << endl << endl;
                        break;
                    } else {
                        bool availableProducts = false;
                        for (int i = 0; i < stockobj->getStock_count(); i++) {
                            if (stockobj->getprodinfo(i) > 0) {
                                availableProducts = true;
                                break;
                            }
                        }

                        if (!availableProducts) {
                            cout << endl;
                            cout << "\033[33mAll Products are Out of Stock\033[0m" << endl << endl;
                            break;
                        }

                        cout << endl;
                        cout << "\033[33mProducts List : \033[0m" << endl;
                        stockobj->print();
                        cout << endl;
                        cout << "How Many Products Do You Want To Order [0 - 100] :";
                        int j;
                        cin >> j;
                        cout << "    Set The ID Of The Order : ";
                        int w;
                        cin >> w;
                        this->setid(w);
                        cout << endl;
                        do {
                            int x;
                            do {
                                cout << endl;
                                cout << "[*] " << "\033[33mEnter The ID Of The Product You Want To Order (0 to exit): \033[0m";
                                cin >> x;
                                if (x == 0) {
                                    break;
                                }
                                cout << endl;
                                if (stockobj->getprodid(x) && stockobj->getprodinfo(x) != 0) {
                                    int qty;
                                    do {
                                        cout << "    Quantity : ";
                                        cin >> qty;
                                        if (stockobj->getprodinfo(x) >= qty) {
                                            j--;
                                            orderlist[order_count] = new orderitem(stockobj, stockobj->getindex(x));
                                            orderlist[order_count]->setsaleprice();
                                            cout << endl;
                                            amount += orderlist[order_count]->getsaleprice() * qty;
                                            cout << "[*] " << "\033[33mThe Total Price Including Shipping Will be  \033[0m"
                                                 << amount << "\n\n    Do You Want To Proceed In The Order [y/n] :";
                                            string y;
                                            cin >> y;

                                            if (y == "y" || y == "Y") {
                                                prodlist[order_count] = stockobj->getProduct(stockobj->getindex(x));
                                                orderlist[order_count] = orderlist[order_count] - qty;
                                                stockobj->decrementProductQuantityBy(stockobj->getindex(x), qty);

                                                orderStatus = "New";
                                                order_count++;
                                                cout << endl;
                                                cout << "    Order Completed." << endl;
                                            }
                                            break;
                                        } else {
                                            cout << "    Error [Quantity Exceeded]\n\n";
                                        }
                                    } while (true);
                                    break;
                                } else if (stockobj->getprodinfo(x) == 0) {
                                    cout << "Product is Out Of Stock" << endl;
                                } else {
                                    cout << endl;
                                    cout << "    Invalid ID  " << endl;
                                }
                            } while (true);
                            if (x == 0) {
                                break;
                            }
                        } while (j != 0);
                    }
                }
                break;
            } else {
                cout << "Invalid ID :";
                cin >> id;
            }
        } while (true);
    }
}


void order::print ()
{
    if (order_count!=0)
    {
        cout << "[*] "
             << "\033[33mCustomer: \033[0m"<<endl<<endl;
        cuslocallist->print();
        cout<<endl<<endl;
        cout << "[*] "
             << "\033[33mOrder Receipt : \033[0m"<<endl<<endl;
        cout << "    Order ID: " << id << endl;
        cout << "    Order Number: " << number << endl;
        cout << "    Order Date: " << date << endl<<endl;
        for (int i =0 ; i<order_count; i++)
        {
            prodlist[i]->printorder();
            cout<<endl;
        }
        cout<<endl;
        cout << "    Total Amount: $" << amount << endl;
        cout<<"    State : "<<orderStatus<<endl;
        cout << "==============================================" << endl;
    }
    else
    {
        cout<<" Orders List Is Empty."<<endl;
    }
}
void order::updateorder()
{
    if(order_count!=0)
    {
        cout << "\033[33m| 1 |\033[0m"
             << " Add Product In The Order" << endl;
        cout << "\033[33m| 2 |\033[0m"
             << " Change Product In The Order" << endl;
        cout << "\033[33m| 3 |\033[0m"
             << " Change Order State" << endl << endl;
        cout << "[*] "
             << "\033[33mChoose The Method : \033[0m";
        string x;
        cin>>x;
        if(x == "1")
        {
            system("CLS");
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << setw(50) << setfill('*') << "" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            cout << setw(32) << setfill(' ') << "ORDER UPDATE" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << setw(50) << setfill('*') << "" << endl;
            cout << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

            cout<<"\033[33mProducts List : \033[0m"<<endl;
            stockobj->print();
            cout<<endl;
            cout<<"How Many Products Do You Want To Order [0 - 100] :";
            int j;
            cin>>j;
            do
            {
                do
                {
                    int x;
                    cout << endl;
                    cout << "[*] " << "\033[33mEnter The ID Of The Product You Want To Order (0 to exit): \033[0m";
                    cin >> x;
                    if (x == 0) {
                        break;
                        }
                    cout << endl;
                    if(stockobj->getprodid(x)&&stockobj->getprodinfo(x)!=0)
                    {

                        do
                        {

                            cout<<"    Quantity : ";
                            int qty;
                            cin>>qty;
                            if(stockobj->getprodinfo(x)>=qty)
                            {
                                j--;
                                orderlist[order_count]= new orderitem(stockobj,stockobj->getindex(x));
                                orderlist[order_count]->setsaleprice();
                                cout<<endl;
                                amount += orderlist[order_count]->getsaleprice() * qty;
                                cout << "[*] "
                                     << "\033[33mThe Total Price Including Shipping Will be  \033[0m"
                                     <<amount<<"\n\n    Do You Want To Proceed In The Order [y/n] :";
                                string y;
                                cin>>y;

                                if(y=="y"||y=="Y")
                                {
                                    prodlist[order_count] =stockobj->getProduct(stockobj->getindex(x));
                                    stockobj->decrementProductQuantityBy(stockobj->getindex(x), qty);
                                    orderlist[order_count]-=qty;
                                    orderStatus = "New";
                                    order_count++;
                                    cout<<endl;
                                    cout<<"    Order Completed."<<endl;
                                }
                                break;
                            }
                            else
                            {
                                cout<<"    Error [Quantity Exceeded]\n\n";
                            }
                        }
                        while(true);
                        break;
                    }else if (stockobj->getprodinfo(x)==0){
                        cout<<"    Product is Out Of Stock";
                    }
                    else
                    {
                        cout<<endl;
                        cout<<"    Invalid ID  ";
                        cout<<endl;
                    }
                }
                while(true);
            }
            while (j!=0);
        }
        if(x == "2")
        {
            system("CLS");
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << setw(50) << setfill('*') << "" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            cout << setw(32) << setfill(' ') << "ORDER UPDATE" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << setw(50) << setfill('*') << "" << endl;
            cout << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);


            this->print();
            cout<<endl;
            cout<<"=============================================="<<endl;
            cout << "[*] "
                 << "\033[33mEnter The ID Of The Product You Want To Change : \033[0m";
            int g;
            cin>>g;
            cout<<endl;
            for (int i=0; i<order_count; i++)
            {
                if(prodlist[i]->getid()==g)
                {
                    system("CLS");
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    cout << setw(50) << setfill('*') << "" << endl;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                    cout << setw(32) << setfill(' ') << "ORDER UPDATE" << endl;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    cout << setw(50) << setfill('*') << "" << endl;
                    cout << endl;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

                    cout<<endl;
                    cout<<"\033[33mProducts List : \033[0m"<<endl;
                    stockobj->print();
                    cout<<endl;
                    do
                    {
                        int x;
                    cout << endl;
                    cout << "[*] " << "\033[33mEnter The ID Of The Product You Want To Order (0 to exit): \033[0m";
                    cin >> x;
                    if (x == 0) {
                        break;
                        }
                    cout << endl;
                        if(stockobj->getprodid(x)&&stockobj->getprodinfo(x)!=0)
                        {
                            do
                            {
                                cout<<"    Quantity : ";
                                int qty;
                                cin>>qty;
                                if(stockobj->getprodinfo(g)<=qty)
                                {
                                    orderlist[i]= new orderitem(stockobj,stockobj->getindex(g));
                                    orderlist[i]->setsaleprice();
                                    amount = orderlist[order_count]->getsaleprice() * qty;
                                    cout << "[*] "
                                         << "\033[33mThe Total Price Including Shipping Will be  \033[0m"
                                         <<orderlist[order_count]->getsaleprice()<<"\n\n    Do You Want To Proceed In The Order [y/n] :";
                                    string y;
                                    cin>>y;
                                    if(y=="y"||y=="Y")
                                    {
                                        prodlist[i] =stockobj->getProduct(stockobj->getindex(g));
                                        stockobj->decrementProductQuantityBy(stockobj->getindex(x), qty);
                                        orderlist[i]-=qty;
                                        orderStatus = "New";
                                        cout<<"    Order Update Completed.";
                                    }
                                    break;
                                }
                                else
                                {
                                    cout<<"    Error [Quantity Exceeded]\n\n";
                                }
                            }
                            while(true);
                            break;
                        }
                        else if (stockobj->getprodinfo(x)==0){
                        cout<<"Product is Out Of Stock";
                    }
                        else
                        {
                            cout<<endl;
                            cout<<"    Invalid ID  ";
                            cout<<endl;
                        }
                    }
                    while(true);

                }
                break;
            }


        }
        else if (x == "3")
        {
            system("CLS");
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << setw(50) << setfill('*') << "" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            cout << setw(32) << setfill(' ') << "ORDER UPDATE" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << setw(50) << setfill('*') << "" << endl;
            cout << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

            if (orderStatus == "Paid" || orderStatus == "paid")
            {
                cout << "[*] "
                     << "\033[33mThe State Of The Order Is Already  \033[0m"<< orderStatus << endl<<endl;
                cout << "    You Cannot Change It.";
            }
            else
            {
                cout << "[*] "
                     << "\033[33mThe State Of The Order Is : \033[0m"<< orderStatus << endl<<endl;
                cout<<"    Do You Want To Change It [y/n] :";
                string c;
                cin>>c;
                if (c == "y"||c == "Y")
                {
                    do
                    {
                        cout<<endl;
                        cout<<"    Choose State [New, Hold, Canceled] : ";
                        string k;
                        cin>>k;
                        if(k == "New"|| k == "Hold" || k == "Canceled"||k == "new"|| k == "hold" || k == "canceled")
                        {
                            cout<<endl;
                            cout << "[*] "
                                 << "\033[33mOrder " << getid() << " State Changed From " << orderStatus << " To " << k << "\033[0m";
                            setstate(k);
                            break;
                        }
                        else
                        {
                            cout<<"Invalid Input : ";
                        }
                    }
                    while (true);

                }
            }
        }
    }
}
void order::setstate(string x)
{
    orderStatus = x;
}
ostream& operator<<(ostream& out, order& ord)
{
    ord.print();
    return out;
}
istream& operator>>(istream& in, order& ord)
{
    ord.createorder();
    return in;
}
void order::setid (int x)
{
    id = x;
}
int order::getid()
{
    return id;
}
order::~order()
{

}
