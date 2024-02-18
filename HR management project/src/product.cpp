#include "product.h"

product::product()
{
    quantity = 0;
    price  = 0;
}
void product::setnum(string x){
    number = x;
}
void product::setname(string x){
    name = x;
}
void product::setprice(double x){
    price  = x;
}
void product::settype(int x){
    type = x;
}
void product::setid(int x){
    id  =x;
}
string product::getnum(){
    return number;
}
string product::getname(){
    return name;
}
double product::getprice(){
    return price;
}
int product::gettype(){
    return type;
}
int product::getid(){
    return id ;
}
int product::getquantity(){
    return quantity;
}
void product::setquantity(int x){
    quantity =x;
}
void product::incrementbyquantity(int x){
    quantity += x;
}
void product::incrementquantity(){
    quantity ++;
}
void product::decrementbyquantity(int x){
    quantity -= x;
}
void product::decrementquantity(){
    quantity --;
}
ostream& operator<<(ostream& out, product& prod)
{
    out << "    Product ID : " << prod.getid() << endl
        << "    Product Number : " << prod.getnum()<<endl
        << "    Product Name : " << prod.getname()<<endl
        << "    Product Price : " << prod.getprice()<<endl
        << "    Product Type : " << prod.gettype()<<endl
        << "    Product Quantity : " << prod.getquantity()<<endl;
    return out;
}
istream& operator>>(istream& in, product& prod)
{
    string x;

    cout << "    Product Number : ";
    getline(in >> ws, x);
    prod.setnum(x);
    cout << endl;

    cout << "    Product Name : ";
    getline(in >> ws, x);
    prod.setname(x);
    cout << endl;

    cout << "    Product Price : ";
    string price;
    getline(in >> ws, price);
    prod.setprice(stod(price));
    cout << endl;

    cout << "    Product Type : ";
    getline(in >> ws, x);
    prod.settype(stoi(x));
    cout << endl;

    cout << "    Product Quantity : ";
    getline(in >> ws, x);
    prod.setquantity(stoi(x));
    cout << endl;

    return in;
}

void product::print()
{
    cout<<*this;
}
void product::printorder(){
cout << "    Product ID : " << this->getid() << endl
        << "    Product Name : " << this->getname()<<endl
        << "    Product Quantity : " << this->getquantity()<<endl;
}
void product::getinfo()
{
    cin>>*this;
}
product::~product()
{
    //dtor
}
