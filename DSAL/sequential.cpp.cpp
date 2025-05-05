#include<iostream>
#include<fstream>
using namespace std;

class Student{
    string name;
    int roll_no;
    public:
    void setdata(){
        cout<<"Enter name of student: ";
        cin>>name;
        cout<<"Enter roll no: ";
        cin>>roll_no;
    }

    void display() {
        cout<<"Name: "<<name<<endl;
        cout<<"Roll No: "<<roll_no<<endl;
        cout<<endl;
    }

    bool compare(int key) {
        if(key==roll_no) {
            return true;
        } else {
            return false;
        }
    }

    friend istream &operator>>(istream &i,Student &obj);
    friend ostream &operator<<(ostream &o,Student &obj);
};

istream &operator>>(istream &i, Student &obj) {
    i>>obj.name>>obj.roll_no;

    return i;
}

ostream &operator<<(ostream &o, Student &obj){
    o<<obj.name<<" "<<obj.roll_no<<" ";

    return o;
}

void addStudent(){
    Student s;
    ofstream out;
    out.open("student.txt",ios::app);
    char flag='y';
    while(flag=='y') {
        s.setdata();
        out<<s;
        cout<<"Add more student(y/n): ";
        cin>>flag;
    }
    out.close();
}

void seeStudent() {
    Student s;
    ifstream in;
    in.open("student.txt");
    while(in>>s){
        s.display();
    }
    in.close();
}


bool searchStudend(int key=-1) {
    Student s;
    ifstream in;
    if(key==-1){
        cout << "Enter roll number to be searched: ";
        cin >> key;
    }
    in.open("student.txt");
    while (in >> s)
    {
        if(s.compare(key)) {
            cout<<"Student found"<<endl;
            s.display();
            in.close();
            return true;
        }
    }
    cout<<"Student not found"<<endl;
    in.close();
    return false;
    
}

void deleteStudent()
{
    Student s;
    ofstream out;
    ifstream in;
    in.open("student.txt");
    out.open("temp.txt", ios::app);
    int key;
    cout << "Enter roll number to be deleted: ";
    cin >> key;
    if (!searchStudend(key))
    {
        return;
    }
    while (in >> s)
    {
        if (s.compare(key))
        {
            continue;
        }
        out << s;
    }
    out.close();
    in.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");
    cout << "Record deleted successfully" << endl;
}

int main() {
    Student s;
    while (1)
    {
        int choice;
        cout<<"1.Add student"<<endl;
        cout<<"2.Display student"<<endl;
        cout<<"3.Search student"<<endl;
        cout<<"4.Delete student"<<endl;
        cout<<"5.Exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                addStudent();
                break;
            case 2:
                seeStudent();
                break;
            case 3:
                searchStudend();
                break;
            case 4:
                deleteStudent();
                break;
        }
    }
    

    s.setdata();
    s.display();

    return 0;
}
