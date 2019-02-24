#include <iostream>
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
    bool isCousins(TreeNode *root, int x, int y) {
        int x_depth = -1, y_depth = -2;
        TreeNode *x_parent, *y_parent;
        helper(root, 0, x, y, x_depth, y_depth, x_parent, y_parent);
        return x_depth == y_depth && x_parent != y_parent;
    }

  private:
    void helper(TreeNode *cur, int cur_depth, int &x, int &y, int &x_depth,
                int &y_depth, TreeNode *&x_parent, TreeNode *&y_parent) {
        if (!cur->left) {
            if (cur->left->val == x) {
                x_depth = cur_depth + 1;
                x_parent = cur;
            }
            if (cur->left->val == y) {
                y_depth = cur_depth + 1;
                y_parent = cur;
            }
            helper(cur->left, cur_depth + 1, x, y, x_depth, y_depth, x_parent,
                   y_parent);
        }
        if (!cur->right) {
            if (cur->right->val == x) {
                x_depth = cur_depth + 1;
                x_parent = cur;
            }
            if (cur->right->val == y) {
                y_depth = cur_depth + 1;
                y_parent = cur;
            }
            helper(cur->right, cur_depth + 1, x, y, x_depth, y_depth, x_parent,
                   y_parent);
        }
    }
};