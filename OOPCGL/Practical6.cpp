// '''Write C++ program using STL
// for sorting and searching user
// defined records such as personal
// records (Name, DOB, Telephone
// number etc) using vector
// container.'''
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

class PersonalRecord {
public:
    string name;
    string dob; 
    string phoneNumber;

    PersonalRecord(string n, string d, string p) 
        : name(n), dob(d), phoneNumber(p) {}
};

bool compareByName(const PersonalRecord& a, const PersonalRecord& b) {
    return a.name < b.name;
}

int main() {
    vector<PersonalRecord> records;
    records.push_back(PersonalRecord("Alice", "1992-04-12", "123-456-7890"));
    records.push_back(PersonalRecord("Bob", "1988-05-22", "234-567-8901"));
    records.push_back(PersonalRecord("Charlie", "1990-09-10", "345-678-9012"));
    records.push_back(PersonalRecord("David", "1995-12-15", "456-789-0123"));

    cout << "Original Records:" << endl;
    for (const auto& record : records) {
        cout << record.name << ", " << record.dob << ", " << record.phoneNumber << endl;
    }

    sort(records.begin(), records.end(), compareByName);

    cout << "\nSorted Records by Name:" << endl;
    for (const auto& record : records) {
        cout << record.name << ", " << record.dob << ", " << record.phoneNumber << endl;
    }

    string searchName;
    cout << "\nEnter the name to search: ";
    cin >> searchName;

    stack<PersonalRecord> searchStack; 
    bool found = false;

    for (const auto& record : records) {
        if (record.name == searchName) {
            searchStack.push(record);
            found = true;
            break;
        }
    }

    if (found) {
        cout << "\nRecord found in stack:" << endl;
        PersonalRecord record = searchStack.top();
        cout << record.name << ", " << record.dob << ", " << record.phoneNumber << endl;
    } else {
        cout << "Record not found!" << endl;
    }

    return 0;
}
