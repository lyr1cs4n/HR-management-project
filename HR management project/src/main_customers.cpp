#include "main_customers.h"

main_customers::main_customers(int x)
{
    cus_size = x;
    cuslist = new customers*[cus_size];
    cus_count=0;
}
int main_customers::getCus_count(){
    return cus_count;
}
void main_customers::addcustomers(){
    do{
    string s;
    cout << "[*] "
         << "\033[33mChoose Customer Type (\033[0m"<<"Person"<<"\033[33m - \033[0m"<<"Company"<<"\033[33m) : \033[0m";
    cin>>s;
    cout<<endl;
    if(s=="Person"||s=="person")
    {
        cuslist[cus_count] = new person();
        cuslist[cus_count]->getinfo();
        cus_count++;
        break;
    }
    else if(s=="Company"||s=="company")
    {
        cuslist[cus_count] = new company();
        cuslist[cus_count]->getinfo();
        cus_count++;
        break;
    }
    else
    {
        cout<<"    Invalid input\n\n";
    }
    }while (true);
}
void main_customers::editcustomers(){
     if (cus_count==0)
    {
        cout<<"\033[33m List Is Empty.\033[0m";
    }
    else
    {
        int id;
        bool check=false;
        bool notedited = false;
        cout << "[*] "
             << "\033[33mEnter Customer's Id That You Want To Edit : \033[0m";
        cin >> id;
            for(int i=0; i<cus_count; i++)
            {
                if(cuslist[i]->getid()==id)
                {
                    cuslist[i]->print();
                    cout<<endl;
                    cout << "[*] "
                         << "\033[33mDo You Want To Edit This Customer (y/n) : \033[0m";
                    string x;
                    cin>>x;
                    cout<<endl;
                    if (x=="y"||x=="Y"){
                    cuslist[i]->getinfo();
                    check=true;
                    break;
                }else {
                    notedited = true;
                    break;
                }
                }
            }
            if (check)
            {
                cout << "\033[33m    Edit Is Completed.\033[0m" << endl;
            }
            else if(!check&&!notedited)
            {
                cout << "\033[33m    Customer Not Found.\033[0m" << endl;
            }

    }
}

void main_customers::deletecustomers(){
    if (cus_count==0)
    {
        cout<<"\033[33m List Is Empty.\033[0m";
    }
    else
    {
        int id;
        cout << "[*] "
             <<"\033[33mEnter Customer's ID to Delete : \033[0m";
        cin >> id;
        bool deleted = false;
        bool check=false;
        for (int i = 0; i < cus_count; ++i)
        {
            if (cuslist[i]->getid() == id)
            {
                cuslist[i]->print();
                cout<<endl;
                string x;
                cout << "[*] "
                     << "\033[33mAre You Sure You Want TO Delete This Customer (y/n) : \033[0m";
                cin>>x;
                if(x=="y"||x=="Y")
                {
                    if (i == cus_count - 1)
                    {
                        cus_count--;
                    }
                    else
                    {
                        cuslist[i] = cuslist[cus_count - 1];
                        cus_count--;
                    }
                    deleted = true;
                    break;
                }else {
                    check = true;
                }
            }
        }
        if (deleted)
        {
            cout << "\033[33m    Customer Deleted \033[0m";
        }
         else if(!deleted&&!check)
            {
                cout << "\033[33m    Customer Not Found.\033[0m" << endl;
            }
    }
}
void main_customers::print(){
    int counter;
    cout<<"====================================="<<endl;
    if(cus_count==0)
    {
        cout<<"\033[33m List Is Empty.\033[0m";
    }else{
    for(int i=0; i<cus_count; i++)
    {
        counter++;
        cout<<"Customer "<<counter<<" : "<<endl<<endl;
        cuslist[i]->print();
        cout<<endl;
        cout<<"====================================="<<endl;
    }
    }
}
void main_customers::searchcus()
{
     int key;
            system("CLS");
            cout << "\033[33m| 1 |\033[0m"
                 << " Customer ID" << endl;
            cout << "\033[33m| 2 |\033[0m"
                 << " Customer Name" << endl;
            cout << "\033[33m| 3 |\033[0m"
                 << " Customer Phone" << endl<< endl;
            cout << "[*] "
                 << "\033[33mChoose The Method You Want To Search With: \033[0m";
            cin >> key;
            cout << "\n\n";
            string data;
            if(key == 1){
                cout<<"    Enter Customer's ID: ";
                cin>>data;
            }
            if(key == 2){
                cout<<"    Enter Customer's Name: ";
                cin>>data;
            }
            if(key == 3){
                cout<<"    Enter Customer's Phone: ";
                cin>>data;
            }
    bool check = false;
    if (cus_count == 0)
    {
        cout<<"\033[33m List Is Empty.\033[0m";
    }
    else
    {

        for (int i = 0; i < cus_count; i++)
        {
            if (key == 1)
            {

                if (cuslist[i]->getid() == stoi(data))
                {
                    cout << "\033[33mUser found\n\n\033[0m";
                    cout << "=====================================" << endl;
                    cuslist[i]->print();
                    cout << "=====================================" << endl;
                    check = true;
                    break;
                }
            }
            else if (key == 2)
            {
                if (cuslist[i]->getname() == data)
                {
                    cout << "\033[33mUser found\n\n\033[0m";
                    cout << "=====================================" << endl;
                    cuslist[i]->print();
                    cout << "=====================================" << endl;
                    check = true;
                    break;
                }
            }
            else if (key == 3)
            {
                if (cuslist[i]->getphone() == data)
                {
                    cout << "\033[33mUser found\n\n\033[0m";
                    cout << "=====================================" << endl;
                    cuslist[i]->print();
                    cout << "=====================================" << endl;
                    check = true;
                    break;
                }
            }
        }
        if (!check)
        {
            cout << "\033[33mEmployee Is Not Found\033[0m";
        }
    }
}
bool  main_customers::checkid(int id){
    if (cus_count == 0)
    {
        return false;
    }else {
    for(int i = 0;i<cus_count;i++){
        if(cuslist[i]->getid()==id){
            return true;
            break;
        }
    }
    return false;
    }
}
customers* main_customers::getcus(int id)
{
    if (cus_count == 0)
    {
        return nullptr;
    }
    else
    {
        for (int i = 0; i < cus_count; i++)
        {
            if (cuslist[i]->getid() == id)
            {
                return cuslist[i];
            }
        }

        return nullptr;
    }
}

void main_customers::mainscreen(int key){
    if (key == 1){
        addcustomers();
    }
    else if (key == 2){
        editcustomers();
    }
    else if (key == 3){
        deletecustomers();
    }
    else if (key == 4){
        print();
    }
}
main_customers::~main_customers()
{
   for (int i = 0; i <cus_count ; i++) {
            delete cuslist[i];
        }
}
