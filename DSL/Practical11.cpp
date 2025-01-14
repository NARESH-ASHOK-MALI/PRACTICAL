//  ImplementC++programforexpressionconversionasinfixtopostfixanditsevaluationusing
//  stackbasedongivenconditions:
//  1.Operandsandoperator,bothmustbesinglecharacter.
//  2. InputPostfixexpressionmustbeinadesiredformat.
//  3.Only'+', '-', '*'and'/ 'operatorsareexpected
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

// Function to return the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-') 
        return 1;  // Lower precedence
    if (op == '*' || op == '/')
        return 2;  // Higher precedence
    return 0;
}

// Function to apply an operator to two operands
int applyOperator(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

// Function to convert an infix expression to postfix
string infixToPostfix(const string &infix) {
    stack<char> operators;  // Stack to hold operators
    string postfix = "";     // Result string

    for (char ch : infix) {
        // If it's an operand (a letter or digit), add it to the result
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If it's an opening parenthesis, push it to the stack
        else if (ch == '(') {
            operators.push(ch);
        }
        // If it's a closing parenthesis, pop until '('
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // Remove '(' from the stack
        }
        // If it's an operator, pop operators of higher or equal precedence
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);  // Push the current operator to the stack
        }
    }

    // Pop all remaining operators in the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string &postfix) {
    stack<int> values;  // Stack to hold operands

    for (char ch : postfix) {
        if (isdigit(ch)) {
            values.push(ch - '0');  // Convert char to int and push to the stack
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int b = values.top(); values.pop();  // Get second operand
            int a = values.top(); values.pop();  // Get first operand
            int result = applyOperator(a, b, ch);  // Apply operator
            values.push(result);  // Push the result back to the stack
        }
    }

    return values.top();  // Final result is the last value in the stack
}

int main() {
    string infix, postfix;

    // Step 1: Input infix expression from the user
    cout << "Enter infix expression (e.g. A+B*C-(D/E)): ";
    cin >> infix;

    // Step 2: Convert infix to postfix
    postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    // Step 3: Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    cout << "Result of Postfix Evaluation: " << result << endl;

    return 0;
}
