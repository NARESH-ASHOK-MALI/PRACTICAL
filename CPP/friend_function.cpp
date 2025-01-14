#include<iostream>
using namespace std;
class Marks
{
private:
    int maths,physics,chemistry;
public:
    Marks(){
        maths=0;
        physics=0;
        chemistry=0; 
        cout<<"Default constructor is calling"<<this<<endl; 
};
    Marks(int maths,int physics,int chemistry){
        this->maths=maths;
        this->physics=physics;
        this->chemistry=chemistry;
        cout<<"Parameterized constructor is calling"<<this<<endl;
    };
    void display(){
        cout<<"Maths:"<<maths<<endl<<"Physics:"<<physics<<endl<<"Chemistry:"<<chemistry<<endl;
    }
    friend void update(Marks &);
    friend void percentage(Marks &);
    friend void second :: update(Marks &);   
};
class second:public Marks{
    public:
    void update(Marks &m){
    
    }
};
void update(Marks &m1){
        cout<<"Update"<<&m1<<endl;
        m1.maths=29;
        m1.physics=75;
        m1.chemistry=67;
}
void percentage(Marks &m2){
        cout<<((m2.chemistry+m2.physics+m2.maths)/(3))<<endl;
} 
int main(){
    Marks m1(87,98,56);
    m1.display();
    update(m1);
    m1.display();
    cout<<"Address of m1 is:"<<&m1<<endl;
    percentage(m1);
    //int x=10;
    //int &y=x;
    //cout<<x;
    //cout<<y;
    return 0;
}