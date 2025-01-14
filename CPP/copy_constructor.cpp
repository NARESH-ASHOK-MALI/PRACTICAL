#include<iostream>
using namespace std;
//COPY CONSTRUCTOR
class Mathematics
{
private:
    int num1,num2;
public:
    Mathematics(){//DEFAULT CONSTRUCTOR
        this->num1=0;
        this->num2=0;
        cout<<"\n Default constructor is calling  :"<<this<<endl;
    }
    Mathematics(int num1,int num2){//Paramerized constructor
        this->num1=num1;
        this->num2=num2;
        cout<<"\n Parameterized constructor is calling  :"<<this<<endl;
    }
    Mathematics(const Mathematics & m){//copy constructor
        this->num1=m.num1;
        this->num2=m.num2;
        cout<<"\n COPY contructor is calling   :"<<this<<endl;
    }
    void display(){//function to display output
        cout<<"\n num1 ="<<num1<<endl;
        cout<<"\n num2 ="<<num2<<endl;
    }
    void sum(Mathematics m1,Mathematics m2){
        Mathematics m3;
        m3.num1=m1.num1+m2.num1;
        m3.num2=m1.num2+m2.num2;
        m3.display();
    }
    ~Mathematics(){//destructor
        cout<<"\n Destructor is calling  :"<<this<<endl;
    }
};
int main(){
    Mathematics arr[2];//object is created arr[0],aar[1]
    Mathematics arr1[2]={{23,43},{30,50}};//object is created arr[0],aar[1]
    Mathematics arr2=Mathematics(arr1[0]);
    Mathematics arr3=Mathematics(arr2);
    arr2.display();
    arr3.display();
    arr3.sum(arr1[0],arr1[1]);
    return 0;
}