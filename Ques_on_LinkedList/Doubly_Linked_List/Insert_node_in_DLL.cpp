#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to insert at beginning
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr, head};

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
}

// Function to insert at end
void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert after a given position (1-based index)
void insertAtPosition(Node*& head, int data, int position) {
    if (position == 1) { // Insert at beginning
        insertAtBeginning(head, data);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* newNode = new Node{data, temp, temp->next};

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Function to display the DLL
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    display(head);

    insertAtBeginning(head, 5);
    display(head);

    insertAtPosition(head, 15, 3);
    display(head);

    return 0;
}
