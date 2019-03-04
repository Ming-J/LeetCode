#include <iostream>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
        if (root && root->val < val) {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
        TreeNode *v = new TreeNode(val);
        v->left = root;
        return v;
    }

  private:
    void helper(TreeNode *prev, TreeNode *cur, TreeNode *val) {
        if (cur == NULL) {
            prev->right = val;
            return;
        }
        if (val->val > cur->val) {
            prev->right = val;
            val->left = cur;
        } else {
            if (cur->right == NULL) {
                cur->right = val;
            } else
                helper(cur, cur->right, val);
        }
    }
};