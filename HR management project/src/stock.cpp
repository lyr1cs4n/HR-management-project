#include "stock.h"

stock::stock(int x)
{
    stock_count=0;
    stock_size = x;
    prodlist = new product[stock_size];
}
int stock :: getStock_count(){
    return stock_count;
}
int stock::getProductCount() const {
    return stock_count;
}

product* stock::getProduct(int index) const {
    if (index >= 0 && index < stock_count) {
      return &prodlist[index];
    } else {
      return nullptr;
    }
  }
bool stock::getprodid(int id)
{
    for (int i = 0; i < stock_count; i++)
    {
        if (prodlist[i].getid() == id)
        {
            return true;
        }
    }
    return false;
}
double stock::getprodinfo(int x){
    for (int i=0;i<stock_count;i++){
        if(prodlist[i].getid() == x){
            return prodlist[i].getquantity();
            break;
        }
    }

}
int stock::getindex(int x){
    for (int i=0;i<stock_count;i++){
        if(prodlist[i].getid() == x){
            return i;
            break;
        }
    }
}
product* stock::getproduct(int index) {
    if (index >= 0 && index < stock_count) {
      return &prodlist[index];
    } else {
      return nullptr;
    }
  }

void stock::incrementProductQuantityBy(int index, int quantity )
{
    if (index >= 0 && index < stock_count)
    {
        prodlist[index].incrementbyquantity(quantity);
    }
}
void stock::decrementProductQuantityBy(int index, int quantity )
{
    if (index >= 0 && index < stock_count)
    {
        prodlist[index].decrementbyquantity(quantity);
    }
}
void stock::incrementProductQuantity(int index)
{
    if (index >= 0 && index < stock_count)
    {
        prodlist[index].incrementquantity();
    }
}
void stock::decrementProductQuantity(int index)
{
    if (index >= 0 && index < stock_count)
    {
        prodlist[index].decrementquantity();
    }
}
void stock::addstock()
{

    int id;
    cout << "    Product ID: ";
    cin >> id;
    cout<<endl;
    bool duplicateID = false;
    for (int i = 0; i < stock_count; i++) {
        if (prodlist[i].getid() == id) {
            duplicateID = true;
            break;
        }
    }

    if (duplicateID) {
        cout << "    Error: Product with ID " << id << " already exists in the stock." << endl;
    } else {
        prodlist[stock_count].setid(id);
        prodlist[stock_count].getinfo();
        stock_count++;
        cout << "\033[33m    Product added to stock.\033[0m" << endl;
    }


}
void stock::updatestock()
{
if (stock_count==0)
    {
        cout<<"\033[33m Stock Is Empty.\033[0m";
    }
    else
    {
        cout << "[*] "
             <<"\033[33mDo You Want To Add Quantity To An Existing Product Or New Product [New / Exist] : \033[0m";
        string x;
        cin>>x;
        cout<<endl;
        if (x == "New"||x == "new"){
            stock::addstock();
        }if ( x == "Exist"||x=="exist"){
        int id;
        bool check=false;
        bool notedited = false;
        cout << "[*] "
             << "\033[33mEnter Product's Id That You Want To Update : \033[0m";
        cin >> id;
            for(int i=0; i<stock_count; i++)
            {
                if(prodlist[i].getid()==id)
                {
                    prodlist[i].print();
                    cout<<endl;
                    cout << "[*] "
                         << "\033[33mDo You Want To Update This Product (y/n) : \033[0m";
                    string x;
                    cin>>x;
                    cout<<endl;
                    if (x=="y"||x=="Y"){
                    cout<<"    Enter The Quantity : ";
                    int j;
                    cin>>j;
                    cout<<endl;
                    prodlist[i].setquantity(j);
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
                cout << "\033[33m    Update Is Completed.\033[0m" << endl;
            }
            else if(!check&&!notedited)
            {
                cout << "\033[33m    Product Not Found.\033[0m" << endl;
            }

    }else {
    cout<<"    Invalid Input";
    }
    }
}
void stock::deleteprod()
{
 if (stock_count==0)
    {
        cout<<"\033[33m Stock Is Empty.\033[0m";
    }
    else
    {
        int id;
        cout << "[*] "
             <<"\033[33mEnter Product's ID to Delete : \033[0m";
        cin >> id;
        bool deleted = false;
        bool check=false;
        for (int i = 0; i < stock_count; ++i)
        {
            if (prodlist[i].getid() == id)
            {
                prodlist[i].print();
                cout<<endl;
                string x;
                cout << "[*] "
                     << "\033[33mAre You Sure You Want TO Delete This Product (y/n) : \033[0m";
                cin>>x;
                if(x=="y"||x=="Y")
                {
                    if (i == stock_count - 1)
                    {
                        stock_count--;
                    }
                    else
                    {
                        prodlist[i] = prodlist[stock_count - 1];
                        stock_count--;
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
            cout << "\033[33m    Product Deleted \033[0m";
        }
         else if(!deleted&&!check)
            {
                cout << "\033[33m    Product Not Found.\033[0m" << endl;
            }
    }
}
void stock::print()
{
    int counter;
    cout<<"====================================="<<endl;
    if(stock_count==0)
    {
        cout<<"\033[33m Stock Is Empty.\033[0m";
    }else{
    for(int i=0; i<stock_count; i++)
    {
        counter++;
        cout<<"Product "<<counter<<" : "<<endl<<endl;
        prodlist[i].print();
        cout<<endl;
        cout<<"====================================="<<endl;
    }
    }
}
void stock::searchcus(string data, int key)
{
 bool check = false;
    if (stock_count == 0)
    {
        cout<<"\033[33m Stock Is Empty.\033[0m";
    }
    else
    {
        for (int i = 0; i < stock_count; i++)
        {
            if (key == 1)
            {
                if (prodlist[i].getid() == stoi(data))
                {
                    cout << "\033[33m Product found\n\n\033[0m";
                    cout << "=====================================" << endl;
                    prodlist[i].print();
                    cout << "=====================================" << endl;
                    check = true;
                    break;
                }
            }
            else if (key == 2)
            {
                if (prodlist[i].getname() == data)
                {
                    cout << "\033[33m Product found\n\n\033[0m";
                    cout << "=====================================" << endl;
                    prodlist[i].print();
                    cout << "=====================================" << endl;
                    check = true;
                    break;
                }
            }
            else if (key == 3)
            {
                if (prodlist[i].getnum() == data)
                {
                    cout << "\033[33m Product found\n\n\033[0m";
                    cout << "=====================================" << endl;
                    prodlist[i].print();
                    cout << "=====================================" << endl;
                    check = true;
                    break;
                }
            }
            else if (key == 4)
            {
                if (prodlist[i].getprice() == stod(data))
                {
                    cout << "\033[33m Product found\n\n\033[0m";
                    cout << "=====================================" << endl;
                    prodlist[i].print();
                    cout << "=====================================" << endl;
                    check = true;
                    break;
                }
            }
            else if (key == 5)
            {
                if (prodlist[i].gettype() == stoi(data))
                {
                    cout << "\033[33m Product found\n\n\033[0m";
                    cout << "=====================================" << endl;
                    prodlist[i].print();
                    cout << "=====================================" << endl;
                    check = true;
                    break;
                }
            }
        }
        if (!check)
        {
            cout << "\033[33m Product Is Not Found\033[0m";
        }


    }
}
void stock::getquantity()
{
    int counter;
    cout<<"====================================="<<endl;
    if(stock_count==0)
    {
        cout<<"\033[33m Stock Is Empty.\033[0m";
    }else{
    for(int i=0; i<stock_count; i++)
    {
        counter++;
        cout << "[*] "
             <<"\033[33mProduct \033[0m"<<prodlist[i].getname()<<" : "<<endl<<endl;
        cout<<"Quantity : "<<prodlist[i].getquantity();
        cout<<endl;
        cout<<"====================================="<<endl;
    }
    }
}
stock::~stock()
{
      delete[] prodlist;
}
