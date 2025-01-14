#include<iostream>
using namespace std;
class cmplx_num{
    int real,img;
    public:
    cmplx_num(){
        this->real=0;
        this->img=0;
    }
    cmplx_num(int r,int i){
        this->real=r;
        this->img=i;
    }
    void dis(){
        cout<<"\n"<<real<<" + "<<img<<" i "<<endl;
    }
    cmplx_num operator+(cmplx_num c1){
        int sum_real,sum_img;
        sum_real=0,sum_img=0;
        for (int i = 0; i < 3; i++){
            sum_real+=(this+i)->real;
            sum_img+=(this+i)->img;
        }
        cmplx_num xyz;
        xyz.real=c1.real+sum_real;
        xyz.img=c1.img+sum_img;
        return xyz;
    }    
    cmplx_num operator+(cmplx_num *ptr){
        int sum_real,sum_imag;
        sum_real=0;
        sum_imag=0;
        for (int i = 0; i < 3; i++){
            sum_real+=(ptr+i)->real;
            sum_imag+=(ptr+i)->img;
        }
        cmplx_num xyz;
        xyz.real=this->real+sum_real;
        xyz.img=this->img+sum_imag;
        return xyz;
    }  
};
int main(){
    cmplx_num c1[3]={{2,3},{4,5},{6,7}};
    cmplx_num c2[3]={{2,3},{4,5},{6,7}};
    cmplx_num c3[3]={{2,3},{4,5},{6,7}};  //Case 1
    cmplx_num c4=*c1+c2+c3; //Case 2 
    c4.dis();
    return 0;
}