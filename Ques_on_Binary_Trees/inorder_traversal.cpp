#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;

        //Traverse left subtree
        inorder(root->left, result);
        //Visit root
        result.push_back(root->val);
        //Traverse right subtree
        inorder(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> ans = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
