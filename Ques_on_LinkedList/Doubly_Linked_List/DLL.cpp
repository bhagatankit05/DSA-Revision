#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // linking nodes
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // print doubly LL

    Node *temp = head;
    cout << "Doubly Linked List : ";
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
        {
            cout << "<->";
        }
        temp = temp->next;
    }

    return 0;
}