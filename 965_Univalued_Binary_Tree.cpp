#include <iostream>
#include <stack>
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
    bool isUnivalTree(TreeNode *root) {
        if (root == NULL)
            return true;
        int prev = root->val;
        stack<TreeNode *> dfs;
        dfs.push(root);
        while (!dfs.empty()) {
            TreeNode *current = dfs.top();
            dfs.pop();
            if (current->val != prev)
                return false;
            if (current->left != NULL)
                dfs.push(current->left);
            if (current->right != NULL)
                dfs.push(current->right);
        }
        return true;
    }
};