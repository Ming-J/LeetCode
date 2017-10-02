#include <iostream>
#include <queue>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
      if(s==NULL&&t==NULL){
	return true;
      }
      if(s==NULL||t==NULL){
	return false;
      }
      if(identical(s,t)){
	return true;
      }
      return isSubtree(s->left,t)||isSubtree(s->right,t);      
    }
  
  bool identical(TreeNode* same, TreeNode* t){
    queue<TreeNode*> maintree;
    queue<TreeNode*> subtree;
    maintree.push(same);
      subtree.push(t);
      while(!subtree.empty()){
	TreeNode* s1=subtree.front();
	subtree.pop();
	TreeNode* m1=maintree.front();
	maintree.pop();
	if(s1->val!=m1->val){
	  return false;
	}
	if(s1->left!=NULL){
	  subtree.push(s1->left);
	}
	if(s1->right!=NULL){
	  subtree.push(s1->right);
	}
	if(m1->left!=NULL){
	  maintree.push(m1->left);
	}
	if(m1->right!=NULL){
	  maintree.push(m1->right);
	 }
      }
      if(!maintree.empty()){
	return false;
      }
      return true;

  }
  

  void subtreeHelper(TreeNode* s, TreeNode* t, TreeNode* &same){
    if(s->val==t->val){
      same=s;
    }else{
      if(s->left!=NULL){
	subtreeHelper(s->left,t,same);
      }
      if(s->right!=NULL){
	subtreeHelper(s->right,t,same);
      }
    }
  }
};
