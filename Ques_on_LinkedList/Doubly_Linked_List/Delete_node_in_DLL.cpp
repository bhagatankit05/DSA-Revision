#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to insert node at end (for testing)
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

// Function to delete from beginning
void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete temp;
}

// Function to delete from end
void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    if (temp->prev != nullptr)
        temp->prev->next = nullptr;
    else
        head = nullptr; // list had only one node

    delete temp;
}

// Function to delete at given position (1-based index)
void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    for (int i = 1; temp != nullptr && i < position; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
}

// Function to display DLL
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    // Insert some test nodes
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    display(head);

    // Delete from beginning
    deleteFromBeginning(head);
    display(head);

    // Delete from end
    deleteFromEnd(head);
    display(head);

    // Delete at position (2nd node)
    deleteAtPosition(head, 2);
    display(head);

    return 0;
}
