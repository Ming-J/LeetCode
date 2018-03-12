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
  void flatten(TreeNode* root) {
    if(root == NULL){
      return;
    }
    TreeNode* leftEnd;
    if(root->left != NULL){
      flatten(root->left);
      leftEnd = root->left;
    }
    while(leftEnd->right != NULL){
      leftEnd = leftEnd -> left;
    }
    TreeNode* righttemp = root->right;
    root -> right = root -> left;
    root -> left = NULL;
    leftEnd -> right = righttemp;
    flatten(root->right);
  }
};
