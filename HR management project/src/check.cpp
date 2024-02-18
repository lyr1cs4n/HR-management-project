#include "check.h"

check::check()
{

}
void check::getinfo ()
{
    cout<<"    Enter Name : ";
    cin>>name;
    cout<<endl;
    cin.ignore();
    cout<<"    Enter Bank ID : ";
    cin>>bank_id;
    cout<<endl;
    payment::getinfo();
}
void check::print ()
{
    payment::print();
    cout<<"    Name : "<<name<<endl
        <<"    Bank ID :"<<bank_id<<endl;
}
void check::setname(string x)
{
    name  =  x;
}
void check::setbank_id(string x)
{
    bank_id = x;
}
string check::getname()
{
    return name;
}
string check::getbank_id()
{
    return bank_id;
}
check::~check()
{
    //dtor
}
