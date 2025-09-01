#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// function to insert node at end
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL; // last node always point to a NULL

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print Linkedlist
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data <<"->";
        temp = temp->next;
    }
    cout <<"null"<<endl;
}

int main()
{
    Node *head = NULL;

    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 50);
    insertAtEnd(head, 70);

    cout << "Singly LinkedList : ";
    printList(head);

    return 0;
}