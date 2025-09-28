#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string postfixToPrefix(string postfix) {
    stack<string> s;
    
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        if (isOperator(c)) {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string temp = c + op1 + op2; // Prefix order
            s.push(temp);
        } else {
            s.push(string(1, c));
        }
    }
    
    return s.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;
    
    string prefix = postfixToPrefix(postfix);
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}
