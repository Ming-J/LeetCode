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
    TreeNode* leftEnd=root->left;
    TreeNode* rightTemp = root->right;
    flatten(root->left);
    //traverse to the end of the flatten linked list
    while(leftEnd!=NULL&&leftEnd->right != NULL){
      leftEnd = leftEnd -> right;
    }
    if(leftEnd != NULL){
      leftEnd -> right = righttemp;
      root -> right = root -> left;
      root -> left = NULL;
    }
    flatten(righttemp);
  }
};
