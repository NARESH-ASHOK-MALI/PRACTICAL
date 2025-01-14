/*In any language program mostly syntax error occurs due to unbalancing delimiter such as
(),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not.*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isWellParenthesized(const string &expression) {
    stack<char> s;
    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}
int main() {
    cout<<"User is Naresh Ashok Mali SCOD16"<<endl;
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);
    if (isWellParenthesized(expression)) {
        cout << "The expression is well-parenthesized." <<endl;
    } else {
        cout << "The expression is not well-parenthesized." <<endl;
    }
    return 0;
}
