#include "company.h"

company::company()
{
    //ctor
}
void company::setlocation(string x){
    location = x;
}
void company::setcom_name(string x){
    company_name = x;
}
string company::getlocation(){
    return location;
}
string company::getname(){
    return company_name;
}
ostream& operator<<(ostream& out, company& j)
{
    out << "    Company Name : " << j.getname() << endl
        << "    Location : " << j.getlocation()<<endl;
    return out;
}
istream& operator>>(istream& in, company& j)
{
    cout << "    Enter Company Name: ";
    string x;
    getline(in, x);
    j.setcom_name(x);
    cout<<endl;
    cout << "    Enter Location: ";
    getline(in, x);
    j.setlocation(x);
    cout<<endl;
    return in;
}

void company::getinfo(){
    customers::getinfo();
    cin>>*this;
}
void company::print (){
    customers::print();
    cout<<*this;
}
company::~company()
{
    //dtor
}
