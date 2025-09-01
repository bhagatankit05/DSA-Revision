#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

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

bool search(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node *head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};
    head->next->next->next = new Node{40, NULL};

    cout << "Linked List : ";
    printLL(head);

    int key = 20;

    if (search(head, key))
    {
        cout << key << " is present in Linked List" << endl;
    }
    else
    {
        cout << key << " is NOT present in Linked List" << endl;
    }

    return 0;
}