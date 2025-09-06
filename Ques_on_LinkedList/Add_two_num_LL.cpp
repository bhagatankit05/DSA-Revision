#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert at end
void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Add two numbers represented by linked lists
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* curr = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        curr->next = new Node(sum % 10);
        curr = curr->next;
    }
    return dummy->next;
}

int main() {
    Node* num1 = nullptr;
    Node* num2 = nullptr;

  
    insertEnd(num1, 2);
    insertEnd(num1, 4);
    insertEnd(num1, 3);

   
    insertEnd(num2, 5);
    insertEnd(num2, 6);
    insertEnd(num2, 4);

    cout << "Number 1: ";
    printList(num1);
    cout << "Number 2: ";
    printList(num2);

    Node* result = addTwoNumbers(num1, num2);

    cout << "Sum: ";
    printList(result);

    return 0;
}
