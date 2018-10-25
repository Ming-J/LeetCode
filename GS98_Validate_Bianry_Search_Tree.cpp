#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
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
    bool isValidBST(TreeNode* root) {
      if(root == NULL) return true;
      bool isValid = true;
      long prev = numeric_limits<long>::min();
      valid(root,prev,isValid);
      return isValid;
    }

  void valid(TreeNode* n,long& prev, bool& isValid){
    if(isValid == false) return;
    if(n->left != NULL) valid(n->left,prev,isValid);
    if(prev == numeric_limits<long>::min()) prev = n->val;
    else
      if(prev >= n->val) isValid = false;
    prev = n ->val;
    if(n->right != NULL) valid(n->right,prev,isValid);
  }
  
};
