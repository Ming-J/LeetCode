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
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
        if (voyage.front() != root->val) {
            return {-1};
        }
        vector<int> ans;
        int ind = 0;
        helper(root, voyage, ind, ans);
        return ans;
    }

    void helper(TreeNode *node, vector<int> &voyage, int &ind,
                vector<int> &ans) {
        if (node == NULL || (!ans.empty() && ans[0] == -1))
            return;
        if (node->val != voyage[ind]) {
            ans = {-1};
            return;
        }
        if (node->left != NULL && ind + 1 < voyage.size() &&
            node->left->val != voyage[ind + 1]) {
            ans.push_back(node->val);
            swap(node->left,node->right);
        }
        if (node->left != NULL) {
            ++ind;
            helper(node->left, voyage, ind, ans);
        }
        if (node->right != NULL) {
            ++ind;
            helper(node->right, voyage, ind, ans);
        }
    }
};