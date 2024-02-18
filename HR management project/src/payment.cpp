#include "payment.h"

payment::payment()
{
    amount  = 0;
    date = __DATE__;
}
void payment::getinfo(){
    cout<<"    Enter Amount :";
    cin>>amount;
}
double payment::getamount (){
    return amount;
}
void payment::print (){
    cout<<"    Amount : "<<amount<<endl
    <<"    Date :"<<date<<endl;
}
string payment::getdate(){
    return date;
}
payment::~payment()
{

}
