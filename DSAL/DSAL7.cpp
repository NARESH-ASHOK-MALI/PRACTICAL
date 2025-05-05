#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX = 50;
class Employee {
public:
    int empid;
    char name[MAX], city[MAX], role[MAX];
    int salary;

    Employee() {
        empid = salary = 0;
        strcpy(name, "");
        strcpy(city, "");
        strcpy(role, "");
    }

    Employee(int empid, const char name[MAX], int salary, const char role[MAX], const char city[MAX]) {
        this->empid = empid;
        this->salary = salary;
        strcpy(this->name, name);
        strcpy(this->city, city);
        strcpy(this->role, role);
    }

    void displayRecord() const {
        cout << endl << setw(5) << empid << setw(20) << name << setw(10) << salary
             << setw(15) << role << setw(15) << city;
    }
};

//========== File Operations ===========
class FileOperations {
    string filename;

public:
    FileOperations(const string& filename) {
        this->filename = filename;
    }

    void insertRecord(int empid, const char name[MAX], int salary, const char role[MAX], const char city[MAX]) {
        ofstream file(filename, ios::app);
        if (!file) {
            cerr << "Error opening file!" << endl;
            return;
        }
        file << empid << "," << name << "," << salary << "," << role << "," << city << endl;
        file.close();
        cout << "\nRecord Inserted.";
    }

    void displayAll() {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file!" << endl;
            return;
        }
        cout << endl << setw(5) << "ID" << setw(20) << "NAME" << setw(10) << "SALARY"
             << setw(15) << "ROLE" << setw(15) << "CITY";

        int empid, salary;
        char name[MAX], role[MAX], city[MAX];
        while (file >> empid) {
            file.ignore(); // Ignore comma
            file.getline(name, MAX, ',');
            file >> salary;
            file.ignore(); // Ignore comma
            file.getline(role, MAX, ',');
            file.getline(city, MAX);

            Employee e(empid, name, salary, role, city);
            e.displayRecord();
        }
        file.close();
    }

    void displayRecord(int empid) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file!" << endl;
            return;
        }

        int id, salary;
        char name[MAX], role[MAX], city[MAX];
        bool found = false;

        while (file >> id) {
            file.ignore();
            file.getline(name, MAX, ',');
            file >> salary;
            file.ignore();
            file.getline(role, MAX, ',');
            file.getline(city, MAX);

            if (id == empid) {
                Employee e(id, name, salary, role, city);
                e.displayRecord();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\nRecord of " << empid << " is not present.";
        }
        file.close();
    }

    void deleteRecord(int empid) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file!" << endl;
            return;
        }

        ofstream temp("temp.txt");
        if (!temp) {
            cerr << "Error creating temporary file!" << endl;
            return;
        }

        int id, salary;
        char name[MAX], role[MAX], city[MAX];
        bool found = false;

        while (file >> id) {
            file.ignore();
            file.getline(name, MAX, ',');
            file >> salary;
            file.ignore();
            file.getline(role, MAX, ',');
            file.getline(city, MAX);

            if (id == empid) {
                found = true;
                continue; // Skip writing to temp file
            }
            temp << id << "," << name << "," << salary << "," << role << "," << city << endl;
        }
        file.close();
        temp.close();

        if (!found) {
            cout << "\nRecord of " << empid << " is not present.";
        } else {
            remove(filename.c_str());
            rename("temp.txt", filename.c_str());
            cout << "\nRecord Deleted Successfully!";
        }
    }
};

int main() {
    cout<<"Program Executor is: Naresh Ashok Mali Roll No:SCOD16"<<endl;

    FileOperations file("Employee.txt");
    int empid, salary, choice = 0;
    char name[MAX], city[MAX], role[MAX];

    while (choice != 5) {
        cout << "\n\n** Employee Database **\n";
        cout << "1) Add New Record\n";
        cout << "2) Display All Records\n";
        cout << "3) Display by Employee ID\n";
        cout << "4) Delete a Record\n";
        cout << "5) Exit\n";
        cout << "Choose your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "\nEnter Employee ID: ";
                cin >> empid;
                cin.ignore();
                cout << "Enter Name: ";
                cin.getline(name, MAX);
                cout << "Enter Salary: ";
                cin >> salary;
                cin.ignore();
                cout << "Enter Role: ";
                cin.getline(role, MAX);
                cout << "Enter City: ";
                cin.getline(city, MAX);
                file.insertRecord(empid, name, salary, role, city);
                break;

            case 2:
                file.displayAll();
                break;

            case 3:
                cout << "Enter Employee ID: ";
                cin >> empid;
                file.displayRecord(empid);
                break;

            case 4:
                cout << "Enter Employee ID: ";
                cin >> empid;
                file.deleteRecord(empid);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.";
        }
    }
    return 0;
}