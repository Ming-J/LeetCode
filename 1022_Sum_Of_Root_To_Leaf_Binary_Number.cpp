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
  int sumRootToLeaf(TreeNode *root) {
    unsigned long total = 0;
    helper(root, 0, total);
    return total;
  }

private:
  void helper(TreeNode *cur, unsigned long val, unsigned long &total) {
    if (cur != NULL) {
      val = val * 2 + cur->val;
      if (cur->left == NULL && cur->right == NULL) {
        total += val;
      } else {
        helper(cur->left, val, total);
        helper(cur->right, val, total);
      }
    }
  }
};

int main() {
  TreeNode *root = new TreeNode(1);
  TreeNode *left = new TreeNode(2);
  root->left = left;
  Solution t;
  t.sumRootToLeaf(root);
}
