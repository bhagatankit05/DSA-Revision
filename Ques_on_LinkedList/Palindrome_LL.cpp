#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    // Function to check palindrome
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) 
                return true; // single node or empty list is palindrome

        // Step 1: Find middle slow will stop at middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        slow->next = reverseList(slow->next);

        // Step 3: Compare first and second halves
        ListNode* first = head;
        ListNode* second = slow->next;
        while (second) {
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};