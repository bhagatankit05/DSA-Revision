#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;

        //Visit root
        result.push_back(root->val);
        //Traverse left subtree
        preorder(root->left, result);
        //Traverse right subtree
        preorder(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> ans = sol.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
