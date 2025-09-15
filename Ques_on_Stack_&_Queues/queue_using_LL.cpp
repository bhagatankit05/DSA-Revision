#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Queue class
class Queue {
private:
    Node* front; 
    Node* rear; 

public:
    // Constructor
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue operation (insert at rear)
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) { // queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued to queue\n";
    }

    // Dequeue operation (remove from front)
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow! Cannot dequeue.\n";
            return;
        }
        Node* temp = front;
        cout << temp->data << " dequeued from queue\n";
        front = front->next;

        // if queue becomes empty, rear should also be null
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    // Peek operation 
    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display all elements
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.peek();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}
