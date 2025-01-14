#include<iostream>
using namespace std;
class Base
{
    public: Base (){
        cout<<"\n Base class constructor is calling "<<endl;
    }
    void check(){
        cout<<"\n Base check is calling"<<endl;
    }
};
class Derived : public Base
{
    public: Derived(){
        cout<<"\n Derived class consttructor is calling"<<endl;
    }
    void check(){
        cout<<"\n Derived check is calling"<<endl;
    }
};
int main (){
    Base b;
    b.check();
    Derived d;
    d.check();
    return 0;
}