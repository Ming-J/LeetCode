#include <iostream>
#include <queue>
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
    bool isCompleteTree(TreeNode *root) {
        if (root == NULL)
            return true;
        queue<TreeNode *> bfs;
        bfs.push(root);
        bool noNull = true;
        bool nodeAfterNULL = true;
        while (!bfs.empty()) {
            size_t lv_size = bfs.size();
            for (size_t i = 0; i < lv_size; ++i) {
                TreeNode *current = bfs.front();
                bfs.pop();
                if (!noNull && current != NULL)
                    return false;
                if (current == NULL) {
                    noNull = false;
                    continue;
                }
                bfs.push(current->left);
                bfs.push(current->right);
            }
        }
        return true;
    }
};