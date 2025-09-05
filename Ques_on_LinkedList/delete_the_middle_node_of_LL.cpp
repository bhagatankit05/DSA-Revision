#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert node at end
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to delete the middle node
void deleteMiddle(Node*& head) {
    if (!head || !head->next) { 
        delete head;
        head = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    // Move slow and fast
    while (fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // slow is now at middle, prev is before it
    prev->next = slow->next;
    delete slow;
}

// Main function
int main() {
    Node* head = nullptr;

    // Insert nodes
    for (int i = 1; i <= 7; i++) {
        insertEnd(head, i);
    }

    cout << "Original List: ";
    printList(head);

    deleteMiddle(head);

    cout << "After Deleting Middle Node: ";
    printList(head);

    return 0;
}
