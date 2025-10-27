#include <iostream>
#include <cmath>
using namespace std;

// Structure for tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftHeight = height(root->left);
        if (leftHeight == -1) return -1; // Left subtree not balanced

        int rightHeight = height(root->right);
        if (rightHeight == -1) return -1; // Right subtree not balanced

        if (abs(leftHeight - rightHeight) > 1)
            return -1; // Current node not balanced

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;
    if (obj.isBalanced(root))
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is NOT balanced." << endl;

    return 0;
}
