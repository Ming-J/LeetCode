#include <iostream>
using namespace std;



//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    invertHelper(root);
    return root;
  }

  void invertHelper(TreeNode* &root){
    if(root==NULL){
      return;
    }
    TreeNode* temp=root->left;
    root->left=root->right;
    root->right=temp;
    invertHelper(root->left);
    invertHelper(root->right);
  }
};
