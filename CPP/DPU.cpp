#include <iostream>
using namespace std;

class DPU {
private:
    string c;

public:
    // Function to get input from the user
    void get() {
        cout << "\nEnter the string to be printed: ";
        cin >> c;
    }

    // Overloaded * operator to print the string multiple times
    DPU operator*(int a) {
        for (int i = 0; i < a; i++) {
            cout << c << " ";
        }
        // Returning the object itself for further usage
        return *this;
    }
};

int main() {
    int y;
    cout << "Enter how many times you want to print: ";
    cin >> y;

    DPU d, d1;
    d.get();
    d1 = d * y;  // Use the user input value instead of a fixed number
    return 0;
}
