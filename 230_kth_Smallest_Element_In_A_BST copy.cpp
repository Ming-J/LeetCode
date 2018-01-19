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
    int res=0;
    kthhelper(root,k,res);
    return res;
  }

  void kthhelper(TreeNode* root, int k, int &val){
    if(root==NULL){
      return;
    }
    kthhelper(root->left, k, val);
    k--;
    if(k==0){
      val= root->val;
    }
    kthhelper(root->right, k, val);
    return;
  }
};
