#include<iostream>
using namespace std;
class cmplx_num{
private:
    int real,img;
public:
    void get(){
        cout<<"\nPlease Enter real & imaginary part of Complex number"<<endl;
        cin>>real>>img;
    }
    void set(){
        cout<<"\n"<<"Complex number is:"<<real<<"+"<<img<<"i"<<endl;
    }
    cmplx_num operator+ (cmplx_num w){
        cmplx_num w1;
        w1.real=this->real+w.real;
        w1.img=this->img+w.img;
        return w1;
    }
    // cmplx_num operator* (cmplx_num y){
    // cmplx_num y1;
    // y1.real=this->real*y.real;
    // y1.img=this->real*y.img;
    // return y1;
    //}this will not multiply iota
    friend cmplx_num operator>>(cmplx_num&,cmplx_num&);
};
cmplx_num operator>> (cmplx_num &c,cmplx_num &w){
    c.real=c.real+w.real;
    c.img=c.img+w.img;
    return c;
}
int main(){
    cmplx_num c1,c2,c3,c4;
    c1.get();
    c1.set();
    c2.get();
    c2.set();
    c3=c1+c2;
    c3.set();
    c4=c1>>c2;
    c4.set();
    return 0;
}