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
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0)
            vector<TreeNode *>();
        return generateSubTree(1, n);
    }

  private:
    vector<TreeNode *> generateSubTree(int start, int end) {
        if (end < start)
            return vector<TreeNode *>{NULL};
        vector<TreeNode *> ans;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode *> left_side = generateSubTree(start, i - 1);
            vector<TreeNode *> right_side = generateSubTree(i + 1, end);

            for (auto le : left_side) {
                for (auto ri : right_side) {
                    TreeNode *root = new TreeNode(i);
                    root->left = le;
                    root->right = ri;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};