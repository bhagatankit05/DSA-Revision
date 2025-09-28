#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

string infixToPrefix(string infix) {
    stack<string> operands;
    stack<char> operators;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                string op2 = operands.top(); operands.pop();
                string op1 = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                string temp = op + op1 + op2;
                operands.push(temp);
            }
            operators.pop(); // remove '('
        }
        else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                string op2 = operands.top(); operands.pop();
                string op1 = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                string temp = op + op1 + op2;
                operands.push(temp);
            }
            operators.push(c);
        }
        else { // Operand
            operands.push(string(1, c));
        }
    }

    while (!operators.empty()) {
        string op2 = operands.top(); operands.pop();
        string op1 = operands.top(); operands.pop();
        char op = operators.top(); operators.pop();
        string temp = op + op1 + op2;
        operands.push(temp);
    }

    return operands.top();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
