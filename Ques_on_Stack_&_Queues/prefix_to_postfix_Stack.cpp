#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string prefixToPostfix(string prefix) {
    stack<string> s;
    
    // Scan from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        
        if (isOperator(c)) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = op1 + op2 + c; // Postfix order
            s.push(temp);
        } else {
            s.push(string(1, c));
        }
    }
    
    return s.top();
}

int main() {
    string prefix;
    cout << "Enter prefix expression: ";
    cin >> prefix;
    
    string postfix = prefixToPostfix(prefix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
