
//Detect loop in a linked list using Floyd's Cycle-Finding Algorithm
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x): data(x), next(nullptr) {}
};

// Returns true if loop exists, false otherwise
bool detectLoopFloyd(Node* head) {
    if (!head) return false;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;           // 1 step
        fast = fast->next->next;     // 2 steps
        if (slow == fast) return true; // meeting point => loop
    }
    return false;
}


//if want to execute this code, copy the code on LeetCode 
//for run this code i require linked list creation code  