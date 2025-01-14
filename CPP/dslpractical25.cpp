/*A palindrome is a string of character that's the same forward and backward. Typically,
punctuation, capitalization, and spaces are ignored. For example, "Poor Dan is in a f
droop" is a palindrome, as can be seen by examining the characters "poor danisina
droop" and observing that they are the same forward and backward. One way to check
for a palindrome is to reverse the characters in the string and then compare with them
the original-in a palindrome, the sequence will be identical. Write C++ program with
functions-
a) To print original string followed by reversed string using stack
b) To check whether given string is palindrome or not*/
#include <iostream>
#include <stack>
#include <cctype> 
#include <string>
using namespace std;
void printReversedString(string str) {
    stack<char> charStack;
    for (char ch : str) {
        if (isalnum(ch)) {  
            charStack.push(ch);
        }
    }
    cout << "Original string: " << str << endl;
    cout << "Reversed string: ";
    while (!charStack.empty()) {
        cout << charStack.top();
        charStack.pop();
    }
    
    cout << endl;
}

// Function to check if a string is a palindrome
bool isPalindrome(string str) {
    string filteredStr = "", reversedStr = "";
    for (char ch : str) {
        if (isalnum(ch)) {
            filteredStr += tolower(ch);
        }
    }
    
    for (int i = filteredStr.length() - 1; i >= 0; i--) {
        reversedStr += filteredStr[i];
    }
    return filteredStr == reversedStr;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    printReversedString(input);
    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
