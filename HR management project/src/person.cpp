#include "person.h"

person::person()
{
    //ctor
}
void person::setaddress(string x){
    address = x;
}
void person::setname(string x){
    name = x;
}
string person::getaddress(){
    return address;
}
string person::getname(){
    return name;
}
ostream& operator<<(ostream& out, person& j)
{
    out << "    Name : " << j.getname() << endl
        << "    Address : " << j.getaddress()<<endl;
    return out;
}

istream& operator>>(istream& in, person& j)
{
   cout << "    Enter Name : ";
    string x;
    getline(in, x);
    j.setname(x);
    cout<<endl;
    cout << "    Enter Address : ";
    getline(in, x);
    j.setaddress(x);
    cout<<endl;
    return in;
}
void person::getinfo(){
    customers::getinfo();
    cin>>*this;
}
void person::print (){
    customers::print();
    cout<<*this;
}
person::~person()
{

}
