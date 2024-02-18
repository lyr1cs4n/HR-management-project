#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <iostream>
#include <bits/stdc++.h>
#include "main_customers.h"
#include "order.h"
#include "transaction.h"
#include "stock.h"

using namespace std;

void clear()
{
    cout << endl;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "saving";
    for (int i = 2; i > 0; i--)
    {
        cout << ".";
        sleep(1);
    }
    system("CLS");
}
void check()
{

    int ch;
    cout << endl;
    cout << endl;
    cout << "\033[33m Press Esc to return back to the main screen. \033[0m";
    do
    {
        ch = getch();
        if (ch == 27)
        {
            system("CLS");
            sleep(1);
        }
    }
    while (ch != 27);
}
void Header(string x)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << setw(50) << setfill('*') << "" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    cout << setw(32) << setfill(' ') << x << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << setw(50) << setfill('*') << "" << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
void StartScreen()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "*****************************************************" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "*                                                   *" << endl;
    cout << "*";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "            Sales Management Project               ";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "*" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "*                                                   *" << endl;
    cout << "*****************************************************" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    cout << "\033[33m| 1 |\033[0m"
         << " Data Entry" << endl;
    cout << "\033[33m| 2 |\033[0m"
         << " Sales Process" << endl;
    cout << "\033[33m| 0 |\033[0m"
         << " Exit program" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "==========================================" << endl;
    cout << "Type your option : ";
}
bool is_integer(string x)
{
    bool ischar = false;
    for (int i = 0; i < x.length(); i++)
    {
        if (!isdigit(x[i]))
        {
            ischar = true;
            break;
        }
    }
    if (ischar)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void customer_menu(main_customers * cus)
{
    int key;
            system("CLS");
            Header("CUSTOMER OPTIONS");
            cout << "\033[33m| 1 |\033[0m"
                 << " Add Customer" << endl;
            cout << "\033[33m| 2 |\033[0m"
                 << " Edit Customer" << endl;
            cout << "\033[33m| 3 |\033[0m"
                 << " Delete Customer" << endl;
            cout << "\033[33m| 4 |\033[0m"
                 << " Customer List" << endl;
            cout << "\033[33m| 0 |\033[0m"
                 << " Return Main" << endl <<endl;
            cout << "[*] "
                 << "\033[33mChoose The Method You Want To Search With: \033[0m";
            cin >> key;
            cout << "\n\n";

            if (key == 1)
            {
                system("CLS");
                Header("CUSTOMERS ASSIGNMENT");
                cout << "[*] "
                     << "\033[33mHow Many Customers (\033[0m"<<"0 - "<<100<<"\033[33m) : \033[0m";
                int counter=0;
                cin>>counter;
                int sum=counter;
                cout<<endl;
                int n=0;
                do
                {
                    n++;
                    cout<<endl;
                    cus->addcustomers();
                    clear();
                    Header("CUSTOMERS ASSIGNMENT");
                    cout<<" ("<<n+1<<"/"<<sum<<")"<<endl<<endl;
                    counter--;
                }
                while(counter!=0);
                system("CLS");
            }

            else if (key == 2)
            {
                system("CLS");
                Header("EDIT CUSTOMERS");
                cus->editcustomers();
                sleep(2);
                system("CLS");
            }

            else if (key == 3)
            {
                system("CLS");
                Header("DELETE CUSTOMERS");
                cus->deletecustomers();
                sleep(2);
                system("CLS");
            }
            else if (key == 4)
            {
                system("CLS");
                Header("CUSTOMERS LIST");
                cus->print();
                check();
            }else {
            system("CLS");
            }

}
void stock_menu(stock * sto)
{
    int key;
            system("CLS");
            Header("STOCKS OPTIONS");
            cout << "\033[33m| 1 |\033[0m"
                 << " Add Product" << endl;
            cout << "\033[33m| 2 |\033[0m"
                 << " Update Product" << endl;
            cout << "\033[33m| 3 |\033[0m"
                 << " Delete Product" << endl;
            cout << "\033[33m| 4 |\033[0m"
                 << " Product List" << endl ;
            cout << "\033[33m| 5 |\033[0m"
                 << " Search Product" << endl ;
            cout << "\033[33m| 6 |\033[0m"
                 << " Products Quantity" << endl;
            cout << "\033[33m| 0 |\033[0m"
                 << " Return Main" << endl <<endl;
            cout << "[*] "
                 << "\033[33mChoose The Method You Want To Search With: \033[0m";
            cin >> key;
            cout << "\n\n";

            if (key == 1)
            {
                system("CLS");
                Header("PRODUCT ASSIGNMENT");
                cout << "[*] "
                     << "\033[33mHow Many Product (\033[0m"<<"0 - "<<100<<"\033[33m) : \033[0m";
                int counter=0;
                cin>>counter;
                int sum=counter;
                cout<<endl;
                int n=0;
                do
                {
                    n++;
                    cout<<endl;
                    sto->addstock();
                    clear();
                    Header("PRODUCT ASSIGNMENT");
                    cout<<" ("<<n+1<<"/"<<sum<<")"<<endl<<endl;
                    counter--;
                }
                while(counter!=0);
                system("CLS");
            }

            else if (key == 2)
            {
                system("CLS");
                Header("UPDATE PRODUCT");
                sto->updatestock();
                sleep(2);
                system("CLS");
            }

            else if (key == 3)
            {
                system("CLS");
                Header("DELETE PRODUCT");
                sto->deleteprod();
                sleep(2);
                system("CLS");
            }
            else if (key == 4)
            {
                system("CLS");
                Header("PRODUCT LIST");
                sto->print();
                check();
            }
            else if (key == 5)
            {
                int key;
                system("CLS");
                Header("SEARCH OPTIONS");
                cout << "\033[33m| 1 |\033[0m"
                     << " Product ID" << endl;
                cout << "\033[33m| 2 |\033[0m"
                     << " Product Name" << endl;
                cout << "\033[33m| 3 |\033[0m"
                     << " Product Number" << endl;
                cout << "\033[33m| 4 |\033[0m"
                     << " Product Price" << endl;
                cout << "\033[33m| 5 |\033[0m"
                     << " Product Type" << endl<< endl;
                cout << "[*] "
                     << "\033[33mChoose The Method You Want To Search With: \033[0m";
                cin >> key;
                cout << "\n\n";

                if (key == 1)
                {
                    cout << "[*] "
                         << "\033[33mEnter Product ID: \033[0m";
                    string data;
                    cin.ignore();
                    getline(cin, data);
                    system("CLS");
                    Header("SEARCHED RESULTS");
                    sto->searchcus(data,key);
                    check();
                }

                if (key == 2)
                {
                    cout << "[*] "
                         << "\033[33mEnter Product Name: \033[0m";
                    string data;
                    cin.ignore();
                    getline(cin, data);
                    system("CLS");
                    Header("SEARCHED RESULTS");
                    sto->searchcus(data,key);
                    check();
                }

                if (key == 3)
                {
                    cout << "[*] "
                         << "\033[33mEnter Product Number: \033[0m";
                    string data;
                    cin.ignore();
                    getline(cin, data);
                    system("CLS");
                    Header("SEARCHED RESULTS");
                    sto->searchcus(data,key);
                    check();
                }
                if (key == 4)
                {
                    cout << "[*] "
                         << "\033[33mEnter Product Price: \033[0m";
                    string data;
                    cin.ignore();
                    getline(cin, data);
                    system("CLS");
                    Header("SEARCHED RESULTS");
                    sto->searchcus(data,key);
                    check();
                }
                if (key == 5)
                {
                    cout << "[*] "
                         << "\033[33mEnter Product Type: \033[0m";
                    string data;
                    cin.ignore();
                    getline(cin, data);
                    system("CLS");
                    Header("SEARCHED RESULTS");
                    sto->searchcus(data,key);
                    check();
                }

            }

            else if (key == 6)
            {
                system("CLS");
                Header("PRODUCT QUANTITY");
                sto->getquantity();
                check();
            }
            else {
                    system("CLS");
            }
        }
void data_entry(stock & sto , main_customers & cus)
{
    system("CLS");
    Header("DATA ENTRY");
    cout << "\033[33m| 1 |\033[0m"
         << " Customers" << endl;
    cout << "\033[33m| 2 |\033[0m"
         << " Stock" << endl;
    cout << "\033[33m| 0 |\033[0m"
         << " Return Main" << endl <<endl;
    cout << "[*] "
         << "\033[33mChoose The Method You Want To Search With: \033[0m";
    string key;
    cin >> key;
    cout << "\n\n";

    if (key == "1")
    {
        customer_menu(&cus);
    }
    else if (key == "2"){
        stock_menu(&sto);
    }
    else {
            system("CLS");
    }

}

void sale_menu (order * orderArray,transaction * trans)
{
    system("CLS");
    Header("DATA ENTRY");
    cout << "\033[33m| 1 |\033[0m"
         << " Orders" << endl;
    cout << "\033[33m| 2 |\033[0m"
         << " Transaction" << endl;
    cout << "\033[33m| 0 |\033[0m"
         << " Return Main" << endl <<endl;
    cout << "[*] "
         << "\033[33mChoose The Method You Want To Search With: \033[0m";
    string key;
    cin >> key;
    cout << "\n\n";

    if (key == "1")
    {
            int key;
    static int counter=0;
    system("CLS");
    Header("CUSTOMER OPTIONS");
    cout << "\033[33m| 1 |\033[0m"
         << " Add Order" << endl;
    cout << "\033[33m| 2 |\033[0m"
         << " Update Order" << endl;
    cout << "\033[33m| 3 |\033[0m"
         << " Delete Order" << endl;
    cout << "\033[33m| 4 |\033[0m"
         << " Order List" << endl;
    cout << "\033[33m| 0 |\033[0m"
         << " Return Main" << endl <<endl;
    cout << "[*] "
         << "\033[33mChoose The Method : \033[0m";
    cin >> key;
    cout << "\n\n";

    if (key == 1)
    {
        system("CLS");
        Header("ORDER ADDITION");
        orderArray[counter].createorder();
        cout<<endl;
        cout<<counter;
        counter++;
        clear();
    }

   else if (key == 2)
    {
        system("CLS");
        Header("ORDER Update");
        int x;
        if(counter==0){
            cout<<" There Are No Orders";
            check();
        }else {
        do{
         cout << "[*] "
         << "\033[33mEnter ID Or The Order : \033[0m";
        cin>>x;
        bool check = false;
        for (int i= 0;i<100;i++){
            if(orderArray[i].getid()==x){
                system("CLS");
                Header("ORDER UPDATE");
                orderArray[i].updateorder();
                clear();
                check = true;
                break;
            }
        }
        if(!check){
            cout<<endl;
            cout<<"    Invalid ID"<<endl<<endl;
        }else {
        break;
        }
    }while (true);
    system("CLS");
    }
    }
   else  if (key == 3)
{
    system("CLS");
    Header("ORDER DELETION");
    int idToDelete;
    bool found = false;

    cout << "[*] "
         << "\033[33mEnter the ID of the Order to Delete: \033[0m";
    cin >> idToDelete;

    // Search for the order with the given ID
    for (int i = 0; i < counter; i++)
    {
        if (orderArray[i].getid() == idToDelete)
        {
            // Shift the remaining orders to fill the gap
            for (int j = i; j < counter - 1; j++)
            {
                orderArray[j] = orderArray[j + 1];
            }
            counter--; // Decrease the counter to reflect the deleted order
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "\n    Order with ID " << idToDelete << " has been deleted." << endl;

    }
    else
    {
        cout << "\n    Order with ID " << idToDelete << " not found." << endl;

    }

    check();
}
   else if (key == 4)
{
    system("CLS");
    Header("ORDER LIST");
    if (counter > 0)
    {
        for (int i = 0; i < counter; i++)
        {
            orderArray[i].print();

        }
    }
    else
    {
        cout << "No orders available." << endl;
    }
    check();
}else {
    system("CLS");
}
    }
    else if (key == "2")
    {
       system("CLS");
    Header("DATA ENTRY");
    cout << "\033[33m| 1 |\033[0m"
         << " Check Out" << endl;
    cout << "\033[33m| 2 |\033[0m"
         << " Print Transaction" << endl;
    cout << "\033[33m| 0 |\033[0m"
         << " Return Main" << endl <<endl;
    cout << "[*] "
         << "\033[33mChoose The Method You Want To Search With: \033[0m";
    string key;
    cin >> key;
    cout << "\n\n";

    if (key == "1")
    {
        system("CLS");
        Header("CHECK OUT");
        trans->getorder();
        check();
    }
    else if (key == "2"){
        system("CLS");
        Header("CHECK OUT");
        trans->printTransactions();
        check();
    }
    else {
            system("CLS");
    }
    }
    else {
        system("CLS");
    }
}
int main()
{

    main_customers cus(100);
    stock sto(100);
    order* orderArray = new order[100];
    for (int i = 0; i < 100; i++)
    {
        orderArray[i] = order(100,&sto, &cus);
    }
    transaction trans(orderArray,50);
    int d;
    string x;
    while (true)
    {
        StartScreen();
        cin >> x;
        do
        {
            cout << "\n\n\n";
            if((x=="0"||x=="1"||x=="2")&&is_integer(x))
            {
                break;
            }
            else
            {
                cout << "[*] "
                     << "\033[33mWrong input, Try again. \033[0m\n"<<endl;
                cout <<"\033[33m    Enter a valid input: \033[0m";
                cin>>x;
            }
        }
        while (true);
        d=stoi(x);
        if (d == 0)
        {
            cout << "\033[33mThanks for using my project :) \033[0m" << endl;
            break;
        }

        if (d == 1)
        {
            data_entry(sto,cus);
        }
        if (d == 2)
        {
          sale_menu (orderArray,&trans);
        }
        if(d == 3)
        {

        }
    }
    return 0;
}
