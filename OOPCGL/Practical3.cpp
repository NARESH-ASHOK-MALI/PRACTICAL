'''Imagine a publishing company
which does marketing for book
and audio cassette versions.
Create a class publication that
stores the title (a string) and price
(type float) of publications. From
this class derive two classes:
book which adds a page count
(type int) and tape which adds a
playing time in minutes (type
float). Write a program that
instantiates the book and tape
class, allows user to enter data
and displays the data members. If
an exception is caught, replace
all the data member values with
zero values.'''
#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    Publication(const string& t, float 
    virtual void getData() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        if (cin.fail() || price < 0) {
            throw invalid_argument("Invalid price entered.");
        }
    }

    virtual void displayData() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }

    virtual ~Publication() {}
};

class Book : public Publication {
private:
    int pageCount;

public:
    Book() : Publication(), pageCount(0) {}

    Book(const string& t, float p, int pc) : Publication(t, p), pageCount(pc) {}

    void getData() override {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
        if (cin.fail() || pageCount < 0) {
            throw invalid_argument("Invalid page count entered.");
        }
    }

    void displayData() const override {
        Publication::displayData();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playTime;

public:
    Tape() : Publication(), playTime(0.0) {}

    Tape(const string& t, float p, float pt) : Publication(t, p), playTime(pt) {}

    void getData() override {
        Publication::getData();
        cout << "Enter playing time (in minutes): ";
        cin >> playTime;
        if (cin.fail() || playTime < 0) {
            throw invalid_argument("Invalid playing time entered.");
        }
    }

    void displayData() const override {
        Publication::displayData();
        cout << "Playing Time: " << playTime << " minutes" << endl;
    }
};

int main() {
    try {
        Book book;
        Tape tape;

        cout << "Enter details for book:" << endl;
        book.getData();
        cout << "\nBook Details:" << endl;
        book.displayData();

        cin.ignore(); 
        cout << "\nEnter details for tape:" << endl;
        tape.getData();
        cout << "\nTape Details:" << endl;
        tape.displayData();

    } catch (exception& e) {
        cerr << "Exception occurred: " << e.what() << endl;

        Book book;
        Tape tape;

        cout << "\nData has been reset due to an exception." << endl;
        cout << "\nBook Details After Reset:" << endl;
        book.displayData();

        cout << "\nTape Details After Reset:" << endl;
        tape.displayData();
    }

    return 0;
}
