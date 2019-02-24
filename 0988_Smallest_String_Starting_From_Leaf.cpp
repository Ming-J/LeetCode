#include <algorithm>
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
    string smallestFromLeaf(TreeNode *root) {
        if (root == NULL)
            return "";
        vector<string> words;
        return helper(root, "");
    }

  private:
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string helper(TreeNode *cur, string s) {
        s = alpha[cur->val] + s;
        if (cur->left && cur->right) {
            string lhs = helper(cur->left, s);
            string rhs = helper(cur->right, s);
            return lhs > rhs ? rhs : lhs;
        } else if (cur->right) {
            return helper(cur->right, s);
        } else if (cur->left) {
            return helper(cur->left, s);
        }
        return s;
    }
};