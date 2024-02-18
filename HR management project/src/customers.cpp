#include "customers.h"

customers::customers()
{
    id=0;
    phone="";
}
void customers::setphone(string x)
{
    phone = x;
}
void customers::setid(int x)
{
    id = x;
}
int customers::getid()
{
    return id;
}
string customers::getphone()
{
    return phone;
}
ostream& operator<<(ostream& out, customers& customer)
{
    out << "    ID : " << customer.getid() << endl
        << "    Phone : " << customer.getphone()<<endl;
    return out;
}
istream& operator>>(istream& in, customers& customer)
{
    cout<<"    Enter ID : ";
    string x;
    in.ignore();
    getline(in, x);
    customer.setid(stoi(x));
    cout<<endl;
     cout<<"    Enter Phone : ";
    getline(in, x);
    customer.setphone(x);
    cout<<endl;
    return in;
}
void customers::print()
{
    cout<<*this;
}
void customers::getinfo()
{
    cin>>*this;
}
customers::~customers()
{

}
