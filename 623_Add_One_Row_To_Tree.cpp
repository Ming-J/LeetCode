#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
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
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if(root==NULL) return NULL;
    if(d == 1){
      TreeNode* newLeft = new TreeNode(v);
      newLeft -> left = root;
      return newLeft;
    }else{
      helper(root,1,v,d);
    }
    return root;
  }

  void helper(TreeNode* node,int lvl, int v, int d){
    if(node == NULL) return;
    if(lvl == d - 1){
      TreeNode* newLeft = new TreeNode(v);
      newLeft -> left = node -> left;
      node -> left = newLeft;
      TreeNode* newRight = new TreeNode(v);
      newRight -> right = node -> right;
      node -> right = newRight;
      return;
    }
    helper(node->left,lvl + 1,v,d);
    helper(node->right,lvl + 1,v,d);
  }
};
