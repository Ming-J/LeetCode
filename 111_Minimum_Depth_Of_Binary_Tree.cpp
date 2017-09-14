#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
  int minDepth(TreeNode* root) {
    if(root==NULL){
      return 0;
    }
    if(root->left==NULL&&root->right==NULL){
      return 1;
    }
    stack<TreeNode*> current;
    current.push(root);
    int depth=0;
    while(!current.empty()){
      depth++;
      stack<TreeNode*> newstack;
      int size=current.size();
      for(int i=0;i<size;i++){
	TreeNode* temp=current.top();
	if(temp->left==NULL&&temp->right==NULL){
	  return depth;
	}
	if(temp->left!=NULL){
	  newstack.push(temp->left);2
	}
	if(temp->right!=NULL){
	  newstack.push(temp->right);
	}
	current.pop();
      }
      current=newstack;
    }
    return 0;
  }
};
