// Develop a program in C++ to create a database of student’s
// information system containing the following information: Name,
// Roll number, Class, Division, Date of Birth, Blood group,
// contact address, Telephone number, Driving license no. and
// other. Construct the database with suitable member functions.
// Make use of constructor, default constructor, copy constructor,
// destructor, static member functions, friend class, this
// pointer, inline code and dynamic memory allocation operators-
// new and delete as well as exception
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;
    string otherDetails;

    static int studentCount;

public:
    Student()
        : name(""), 
        rollNumber(0), 
        studentClass(""), 
        division('A'), 
        dateOfBirth(""), 
        bloodGroup(""),
        contactAddress(""),
        telephoneNumber(""), 
        drivingLicenseNo(""), 
        otherDetails("") {
        studentCount++;
    }
    Student(const string& name, 
            int rollNumber, 
            const string& studentClass, 
            char division, 
            const string& dateOfBirth,
            const string& bloodGroup, 
            const string& contactAddress, 
            const string& telephoneNumber,
            const string& drivingLicenseNo, 
            const string& otherDetails)
        : name(name), 
        rollNumber(rollNumber), 
        studentClass(studentClass), 
        division(division),
        dateOfBirth(dateOfBirth),
          bloodGroup(bloodGroup), 
          contactAddress(contactAddress), telephoneNumber(telephoneNumber),
          drivingLicenseNo(drivingLicenseNo), otherDetails(otherDetails) {
        studentCount++;
    }
    Student(const Student& other)
        : name(other.name), rollNumber(other.rollNumber), studentClass(other.studentClass), division(other.division),
          dateOfBirth(other.dateOfBirth), bloodGroup(other.bloodGroup), contactAddress(other.contactAddress),
          telephoneNumber(other.telephoneNumber), drivingLicenseNo(other.drivingLicenseNo),
          otherDetails(other.otherDetails) {
        studentCount++;
    }

    ~Student() {
        studentCount--;
    }

    static int getStudentCount() {
        return studentCount;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No.: " << drivingLicenseNo << endl;
        cout << "Other Details: " << otherDetails << endl;
    }

    friend class Admin;
    inline void setData(const string& name, int rollNumber, const string& studentClass, char division,
                        const string& dateOfBirth, const string& bloodGroup, const string& contactAddress,
                        const string& telephoneNumber, const string& drivingLicenseNo, const string& otherDetails) {
        this->name = name;
        this->rollNumber = rollNumber;
        this->studentClass = studentClass;
        this->division = division;
        this->dateOfBirth = dateOfBirth;
        this->bloodGroup = bloodGroup;
        this->contactAddress = contactAddress;
        this->telephoneNumber = telephoneNumber;
        this->drivingLicenseNo = drivingLicenseNo;
        this->otherDetails = otherDetails;
    }
};

int Student::studentCount = 0;

class Admin {
public:
    void updateContactAddress(Student& student, const string& newAddress) {
        student.contactAddress = newAddress;
    }
};

int main() {
    try {
        vector<Student*> database;
        Student* s1 = new Student("Alice", 1, "10th", 'A', "2006-05-14", "O+", "123 Street, City", "1234567890", "DL12345", "N/A");
        Student* s2 = new Student("Bob", 2, "10th", 'B', "2005-11-22", "A-", "456 Avenue, Town", "9876543210", "DL67890", "N/A");

        database.push_back(s1);
        database.push_back(s2);

        for (const auto& student : database) {
            student->display();
            cout << "--------------------------" << endl;
        }

        cout << "Total Students: " << Student::getStudentCount() << endl;

        Admin admin;
        admin.updateContactAddress(*s1, "789 Boulevard, Metropolis");
        cout << "Updated Address for Alice:" << endl;
        s1->display();

        for (auto& student : database) {
            delete student;
        }

    } catch (exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
