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
    void postorder(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;

        //Traverse left subtree
        postorder(root->left, result);
        //Traverse right subtree
        postorder(root->right, result);
        //Visit root
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> ans = sol.postorderTraversal(root);

    cout << "Postorder Traversal: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
