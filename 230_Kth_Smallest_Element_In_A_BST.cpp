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
  int kthSmallest(TreeNode* root, int k) {
    int ans;
    helper(root,k,ans);
    return ans;
  }
  //Using a helper function to traverse the tree with inorder, as
  //inorder traversal will display the function in sorted order
  void helper(TreeNode* root,int &k,int &val){
    if(root==NULL){
      return;
    }
    helper(root->left,k,val);
    k--;
    if(k==0){
      val=root->val;
      k=-1;
      return;
    }
    helper(root->right,k,val);
  }
};
