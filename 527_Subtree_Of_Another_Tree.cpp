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
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if(s==NULL) return false;
    return checkSame(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);
  }

  bool checkSame(TreeNode* s,TreeNode* t){
    if(s != NULL && t!=NULL){ 
      if(s->val != t->val) return false;
      return checkSame(s->left,t->left)&&checkSame(s->right,t->right);
    }
    return (s==NULL && t ==NULL)?true:false;
  } 

    
};
