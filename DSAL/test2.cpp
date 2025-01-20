#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int roll;
    string name;
    char division;
    string address;

public:
    void EnterData() {
        cout << "Enter the following details:" << endl;
        cout << "Enter Roll No: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Division: ";
        cin >> division;
        cin.ignore();
        cout << "Enter Address: ";
        getline(cin, address);
    }

    void DisplayData() const {
        cout << "Roll No   : " << roll << endl;
        cout << "Name      : " << name << endl;
        cout << "Division  : " << division << endl;
        cout << "Address   : " << address << endl;
    }

    void WriteToTextFile(ofstream &outFile) const {
        outFile << roll << endl;
        outFile << name << endl;
        outFile << division << endl;
        outFile << address << endl;
    }
    bool ReadFromTextFile(ifstream &inFile) {
        if (!(inFile >> roll)) return false;
        inFile.ignore();
        getline(inFile, name);
        inFile >> division;
        inFile.ignore(); 
        getline(inFile, address);
        return true;
    }
};

void WriteRecord() {
    ofstream outFil("students.txt", ios::app);
    if (!outFil) {
        cerr << "Error: Could not open file for writing!" << endl;
        return;
    }

    Student obj;
    obj.EnterData();
    obj.WriteToTextFile(outFil);
    outFil.close();
    cout << "Record added successfully." << endl;
}

void DisplayRecords() {
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error: Could not open file for reading!" << endl;
        return;
    }

    Student obj;
    cout << "Displaying all records:" << endl;
    while (obj.ReadFromTextFile(inFile)) {
        obj.DisplayData();
        cout << "-------------------------" << endl;
    }
    inFile.close();
}

int main() {
    WriteRecord();
    
    DisplayRecords();
    cout << "Exiting program. Goodbye!" << endl;
    return 0;
}
