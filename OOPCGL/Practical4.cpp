// """Write a C++ program that creates
// an output file, writes information
// to it, closes the file, open it again
// as an input file and read the
// information from the file."""
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fileName = "example.txt";
    string dataToWrite = "This is a sample text written to the file.";
    string dataRead;

    // Create and write to the file
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << dataToWrite;
        outFile.close();
        cout << "Data written to file successfully." << endl;
    } else {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    // Open the file for reading
    ifstream inFile(fileName);
    if (inFile.is_open()) {
        getline(inFile, dataRead);
        inFile.close();
        cout << "Data read from file: " << dataRead << endl;
    } else {
        cerr << "Unable to open file for reading." << endl;
        return 1;
    }

    return 0;
}
