#include <iostream>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Use regular traversal, we got an Time Limit Exceeded


class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);    
    }
};
