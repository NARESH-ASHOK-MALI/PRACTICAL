/*Departments maintains a student information, the file contains roll no, name, div, add, allow user to add delet inf of 
student display information of particular students if record of student does not exit an appropriate msg displayed if it is then 
the system displays students detaoils use sequential file to save the data*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student{
    public:
    int roll;
    char name[30];
    char division;
    char address[50];
    //function for accepting data
   
    void insert (){
       cout<<"Enter the following:"<<endl;
       cout<<"Enter roll no:"<<endl;
       cin>>roll;
       cout<<"Enter the Name:"<<endl;
       cin>>name;
       cout<<"Enter the division:"<<endl;
       cin>>division;
       cout<<"Enter the address:"<<endl;
       cin>>address;
    }
    //Function for displaying data
    void display(){
        cout<<"Roll No:"<<roll<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Division:"<<division<<endl;
        cout<<"Address:"<<address<<endl;
    }
    //Function for searching data
    void search(int r){
        if(roll==r){
            cout<<"Roll No:"<<roll<<endl;
            cout<<"Name:"<<name<<endl;
            cout<<"Division:"<<division<<endl;
            cout<<"Address:"<<address<<endl;
        }
        else{
            cout<<"Record not found"<<endl;
        }
    }
    //Function for deleting data
    void del(int r){
        if(roll==r){
            roll=0;
            name[0]='\0';
            division='\0';
            address[0]='\0';
            cout<<"Record deleted"<<endl;
        }
        else{
            cout<<"Record not found"<<endl;
        }
    }
    
};
int main(){
    ofstream file;
    file.open("student.txt");
    file<<"Roll No. Name Division Address\n";
    return 0;
}