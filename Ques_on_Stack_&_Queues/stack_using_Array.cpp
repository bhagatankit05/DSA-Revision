#include <iostream>
using namespace std;

#define MAX 5   

int stack[MAX]; 
int top = -1;  

// Push operation
void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow! Cannot push " << x << endl;
    } else {
        top++;
        stack[top] = x;
        cout << x << " pushed into stack\n";
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Nothing to pop\n";
    } else {
        cout << stack[top] << " popped from stack\n";
        top--;
    }
}

// Peek operation
void peek() {
    if (top == -1) {
        cout << "Stack is empty\n";
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

// Display all elements
void display() {
    if (top == -1) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    peek();

    pop();
    display();

    pop();
    pop();
    pop();  

    return 0;
}
