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
    int distributeCoins(TreeNode *root) {
        int step = 0;
        helper(root,step);
        return step;
    }

  private:
    int helper(TreeNode *node, int &step) {
        if(node == NULL) return 0;
        int left = helper(node->left,  step);
        int right = helper(node->right, step);
        step += abs(left) + abs(right);
        return node->val -1 + left + right;
    }
};