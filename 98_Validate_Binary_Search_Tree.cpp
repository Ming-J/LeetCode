#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
  void validBST(TreeNode* root, int &pre, bool &ans){
    if(root->left){
      validBST(root->left,pre,ans);
    }
    if(pre<root->val){
      pre=root->val;
    }else{
      ans=false;
    }
    if(root->right){
      validBST(root->right,pre,ans);
    }
  }
  bool isValidBST(TreeNode* root) {
    if(root==NULL){
      return false;
    }
    int pre=-1;
    bool ans=true;
    validBST(root,pre,ans);
    return ans;
  }
};
