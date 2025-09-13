#include <iostream>
using namespace std;

#define MAX 5   

int queueArr[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int x) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow! Cannot insert " << x << endl;
    } else {
        if (front == -1) front = 0; 
        queueArr[++rear] = x;
        cout << x << " enqueued into queue\n";
    }
}

// Dequeue operation
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow! Nothing to dequeue\n";
    } else {
        cout << queueArr[front++] << " dequeued from queue\n";
    }
}

// Peek operation
void peek() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty\n";
    } else {
        cout << "Front element is: " << queueArr[front] << endl;
    }
}

// Display queue
void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty\n";
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queueArr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // overflow

    display();

    dequeue();
    dequeue();
    peek();

    display();

    return 0;
}
