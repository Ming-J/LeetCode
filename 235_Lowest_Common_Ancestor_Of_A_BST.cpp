#include <iostream>
#include <vector>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*bad complextiy: as I am storing all the treenode and traversal them
  starting from the leaf to check is the leave contain bost p and q
  node.  A quicker way of doing this will be using the tree porierty
  saying if root is >p,q then we go to the left hand side of the
  tree. If root<p,q then we go to the right hand side. The root with
  root in between p and q are the loest common Ancestor
 */
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> list;
    list.push_back(root);
    for(int i=0;i<list.size();i++){
      if(list[i]->left!=NULL){
	list.push_back(list[i]->left);
      }
      if(list[i]->right!=NULL){
	list.push_back(list[i]->right);
      }
    }
    for(size_t i=list.size();i-->=0;){
      if((helper(list[i],p))&&(helper(list[i],q))){
	return list[i];
      }
    }
    return root;
  }
  
  bool helper(TreeNode* root,TreeNode* check){
    if(root==NULL){
      return false;
    }
    if(root==check){
      return true;
    }
    return helper(root->left,check)||helper(root->right,check);
  }
};
