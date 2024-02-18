#include "credit.h"

credit::credit()
{
    //ctor
}
void credit::getinfo (){
    cout<<"    Enter Number : ";
    cin>>number;
    cout<<"    Enter Expire Date : ";
    cin>>expire_date;
    cout<<"    Enter Type : ";
    cin>>type;
    payment::getinfo();
}
void credit::print (){
    cout<<"    Number :"<<number<<endl
    <<"    Expire Date : "<<expire_date<<endl
    <<"    Type : "<<type<<endl;
    payment::print();
}
void credit::setnumber(string x){
    number = x;
}
void credit::setexpire_date(string x){
    expire_date = x;
}
void credit::settype(string x){
    type = x;
}
string credit::getnumber(){
    return number;
}
string credit::getexpire_date(){
    return expire_date;
}
string credit::gettype(){
    return type;
}
credit::~credit()
{
    //dtor
}
