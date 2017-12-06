#include <iostream>
#include <dequeue>
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
    bool isSymmetric(TreeNode* root) {
      if(root==NULL){
	return true;
      }
      dequeue<TreeNode*> level;
      level.push_back(root);
      while(!level.empty()){
	int lvlength=level.size();
	if(lvlength==1){
	  addnode(level.front(),level);
	  level.pop_front();
	}else{
	  int front=level.front();
	  int back=level.back();
	  
	}
      }
    }

  void addNode(TreeNode* node,dequeue<TreeNode*> &deck){
    if(node->left!=NULL){
      deck.push_back(node->left);
    }
    if(node->right!=NULL){
      deck.push_back(node->right);
    }
  }
};
