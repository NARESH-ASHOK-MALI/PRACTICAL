/*
Name : Naresh Ashok Mali

Problem Statement 1: Department maintains a student information.
The file contains roll number, name, division, and address. 
Allow user to add, delete information of student.
Display information of particular student. 
If record of student does not exist, an appropriate message is displayed. 
If it is, then the system displays the student details.
Use sequential file to maintain the data.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int roll;
    string name;
    char division;
    string address;

    void setdata() {
        cout << "Enter the following:" << endl;
        cout << "Enter roll no: ";
        cin >> roll;
        cin.ignore(); // Handle leftover newline
        cout << "Enter the Name: ";
        getline(cin, name);
        cout << "Enter the division: ";
        cin >> division;
        cin.ignore(); // Handle leftover newline
        cout << "Enter the address: ";
        getline(cin, address);
    }

    void showdata() {
        cout << "Roll No.: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Division: " << division << endl;
        cout << "Address: " << address << endl;
    }
};

void write_record() {
    ofstream outFile("student.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    int n;
    cout << "Enter number of records to add: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Student obj;
        obj.setdata();

        outFile.write((char *)&obj.roll, sizeof(obj.roll));
        outFile.write((char *)&obj.division, sizeof(obj.division));

        size_t nameLength = obj.name.size();
        outFile.write((char *)&nameLength, sizeof(nameLength));
        outFile.write(obj.name.c_str(), nameLength);

        size_t addressLength = obj.address.size();
        outFile.write((char *)&addressLength, sizeof(addressLength));
        outFile.write(obj.address.c_str(), addressLength);
    }

    outFile.close();
    cout << "Record(s) added successfully." << endl;
}

void display() {
    ifstream inFile("student.txt");
    if (!inFile) {
        cout << "No records to display." << endl;
        return;
    }

    Student obj;
    while (inFile.read((char *)&obj.roll, sizeof(obj.roll))) {
        inFile.read((char *)&obj.division, sizeof(obj.division));

        size_t nameLength;
        inFile.read((char *)&nameLength, sizeof(nameLength));
        obj.name.resize(nameLength);
        inFile.read(&obj.name[0], nameLength);

        size_t addressLength;
        inFile.read((char *)&addressLength, sizeof(addressLength));
        obj.address.resize(addressLength);
        inFile.read(&obj.address[0], addressLength);

        obj.showdata();
        cout << "-------------------" << endl;
    }

    inFile.close();
}

int search(int n) {
    ifstream inFile("student.txt");
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return 0;
    }

    Student obj;
    while (inFile.read((char *)&obj.roll, sizeof(obj.roll))) {
        inFile.read((char *)&obj.division, sizeof(obj.division));

        size_t nameLength;
        inFile.read((char *)&nameLength, sizeof(nameLength));
        obj.name.resize(nameLength);
        inFile.read(&obj.name[0], nameLength);

        size_t addressLength;
        inFile.read((char *)&addressLength, sizeof(addressLength));
        obj.address.resize(addressLength);
        inFile.read(&obj.address[0], addressLength);

        if (obj.roll == n) {
            obj.showdata();
            inFile.close();
            return 1;
        }
    }

    cout << "Record of roll no. " << n << " not found." << endl;
    inFile.close();
    return 0;
}

void delete_record(int n) {
    ifstream inFile("student.txt");
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    ofstream outFile("temp.txt");
    if (!outFile) {
        cerr << "Error opening temporary file for writing." << endl;
        inFile.close();
        return;
    }

    Student obj;
    bool found = false;

    while (inFile.read((char *)&obj.roll, sizeof(obj.roll))) {
        inFile.read((char *)&obj.division, sizeof(obj.division));

        size_t nameLength;
        inFile.read((char *)&nameLength, sizeof(nameLength));
        obj.name.resize(nameLength);
        inFile.read(&obj.name[0], nameLength);

        size_t addressLength;
        inFile.read((char *)&addressLength, sizeof(addressLength));
        obj.address.resize(addressLength);
        inFile.read(&obj.address[0], addressLength);

        if (obj.roll != n) {
            outFile.write((char *)&obj.roll, sizeof(obj.roll));
            outFile.write((char *)&obj.division, sizeof(obj.division));

            size_t nameLength = obj.name.size();
            outFile.write((char *)&nameLength, sizeof(nameLength));
            outFile.write(obj.name.c_str(), nameLength);

            size_t addressLength = obj.address.size();
            outFile.write((char *)&addressLength, sizeof(addressLength));
            outFile.write(obj.address.c_str(), addressLength);
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    if (found) {
        remove("student.txt");
        rename("temp.txt", "student.txt");
        cout << "Record deleted successfully." << endl;
    } else {
        cout << "Record not found." << endl;
        remove("temp.txt");
    }
}

int main() {
    
    cout<<"Program Executor : Naresh Ashok Mali Roll no : SCOD 16"<<endl;
    int choice;
    do {
        cout << "<---------------------------------------------------->" << endl;
        cout << "|Menu:  --->                                         |" << endl;
        cout << "|1. Add record                                       |" << endl;
        cout << "|2. Display records                                  |" << endl;
        cout << "|3. Search record                                    |" << endl;
        cout << "|4. Delete a particular record                       |" << endl;
        cout << "|5. Exit                                             |" << endl;
        cout << "|Enter your choice:     --->                         |" << endl;
        cout << "<---------------------------------------------------->"<<endl;
        cin >> choice;


        switch (choice) {
            case 1:
                write_record();
                break;
            case 2:
                display();
                break;
            case 3: {
                cout << "Enter roll number to search: ";
                int roll;
                cin >> roll;
                search(roll);
                break;
            }
            case 4: {
                cout << "Enter roll number to delete: ";
                int roll;
                cin >> roll;
                delete_record(roll);
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
