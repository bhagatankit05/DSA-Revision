#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to insert node at end
void insertEnd(Node*& head, int data) {
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

// Function to print list with arrows
void printList(Node* head) {
    cout << "NULL <- ";
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr)
            cout << " <-> ";
        head = head->next;
    }
    cout << " -> NULL\n";
}

// Function to reverse the doubly linked list
void reverseList(Node*& head) {
    if (!head) return;

    Node* temp = nullptr;
    Node* current = head;

    // Swap prev and next for all nodes
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  // Move to next node (which is prev now)
    }

    // Fix head
    if (temp != nullptr) {
        head = temp->prev;
    }
}
int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Original List: ";
    printList(head);

    reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
