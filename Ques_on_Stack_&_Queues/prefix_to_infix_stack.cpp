#include <bits/stdc++.h>
using namespace std;

// Function to check if symbol is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string prefixToInfix(string prefix) {
    stack<string> s;
    
    // Scan from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        
        if (isOperator(c)) {
            // Pop two operands
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            // Form a string with parentheses
            string temp = "(" + op1 + c + op2 + ")";
            s.push(temp);
        } else {
            // Operand  push as string
            s.push(string(1, c));
        }
    }
    return s.top();
}

int main() {
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;
    
    string infix = prefixToInfix(prefix);
    cout << "Infix expression: " << infix << endl;
    return 0;
}
