#include<iostream>
using namespace std;
void fun(int a){
    
    if (a==19)
    {   
        cout<<"Code executed"<<" ";
        cout<<sum;
        return;
    }
    int sum=5;
    cout<<a<<" ";
    sum=sum+a;
    cout<<sum<<" ";
    a--;
    fun(a);
}
int main(){
    
    fun(20);
    return 0;
}