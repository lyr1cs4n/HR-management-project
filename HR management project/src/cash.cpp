#include "cash.h"

cash::cash()
{
    //ctor
}
void cash::getinfo(){
    cout<<"    Enter Cash Value : ";
    cin>>cashValue;
    payment::getinfo();
}
void cash::print (){
    payment::print();
    cout<<"    Cash Value : "<<cashValue;
}
void cash::setcash(double x){
    cashValue =x;
}
double cash::getcash (){
    return cashValue;
}
cash::~cash()
{
    //dtor
}
