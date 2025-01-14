// Inanylanguageprogrammostlysyntaxerroroccursduetounbalancingdelimitersuchas
//  (),{},[].Write C++ programusing stack to checkwhether given expression iswell
//  parenthesizedornot.
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if a character is an opening bracket
bool isOpeningBracket(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

// Function to check if a character is a closing bracket
bool isClosingBracket(char ch) {
    return (ch == ')' || ch == '}' || ch == ']');
}

// Function to check if brackets match
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') || 
           (open == '{' && close == '}') || 
           (open == '[' && close == ']');
}

// Function to check if the expression is well-parenthesized
bool isWellParenthesized(const string& expression) {
    stack<char> s;

    for (char ch : expression) {
        if (isOpeningBracket(ch)) {
            s.push(ch); // Push opening bracket to the stack
        } else if (isClosingBracket(ch)) {
            if (s.empty() || !isMatchingPair(s.top(), ch)) {
                return false; // Either stack is empty or brackets don't match
            }
            s.pop(); // Pop matching opening bracket
        }
    }

    return s.empty(); // Stack should be empty if all brackets are matched
}

int main() {
    string expression;

    cout << "Enter an expression to check: ";
    getline(cin, expression);

    if (isWellParenthesized(expression)) {
        cout << "The expression is well-parenthesized." << endl;
    } else {
        cout << "The expression is not well-parenthesized." << endl;
    }

    return 0;
}
