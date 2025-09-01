#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Function to delete first Node

void delFirst(Node *&head)
{

    if (head == NULL)
    {
        cout << "LinkedList is empty, deletion not possible" << endl;
        return;
    }

    Node *temp = head; // temp points to current head
    head = head->next; // shifted head to next node
    delete temp;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "Null\n";
}

int main()
{
    // create LL
    Node *head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};
    head->next->next->next = new Node{40, NULL};

    cout << "Original LL : ";
    printLL(head);

    // deleting first node
    delFirst(head);

    cout << "LL after deleting First Node : ";
    printLL(head);
    
    return 0;
}