#include <iostream>
#include <deque>
#include <vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*A beeter solution can be use using two queue instead one one. So I
  am obtaining the level convert them to vector and check the symmetry
  as well as checking them children.
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
      if(root==NULL){
	return true;
      }
      deque<TreeNode*> level;
      level.push_back(root);
      while(!level.empty()){
	int lvlength=level.size();
	if(lvlength==1){
	  addNode(level.front(),level);
	  if(!checkSingle(level.front())){
	      return false;
	    }
	  level.pop_front();
	}else{
	  vector<TreeNode*> temp(level.begin(),level.end());
	  int front=0;
	  int back=temp.size()-1;
	  while(front<back){
	    if(temp[front]->val!=temp[back]->val){
	      return false;
	    }
	    if(!checkChildren(temp[front],temp[back])){
	      return false;
	    }
	    front++;
	    back--;
	  }
	  for(int i=0;i<lvlength;i++){
	    addNode(level.front(),level);
	    level.pop_front();
	  }
	}
      }
      return true;
    }
  bool checkSingle(TreeNode *node){
    if(node->left==NULL&&node->right!=NULL){
      return false;
    }
    if(node->left!=NULL&&node->right==NULL){
      return false;
    }
    return true;
  }
  bool checkChildren(TreeNode* left, TreeNode* right){
    if(left->left==NULL&&right->right!=NULL){
      return false;
    }
    if(left->left!=NULL&&right->right==NULL){
      return false;
    }
    if(left->right==NULL&&right->left!=NULL){
      return false;
    }
    if(left->right!=NULL&&right->left==NULL){
      return false;
    }
    return true;
  }

  void addNode(TreeNode* node,deque<TreeNode*> &deck){
    if(node->left!=NULL){
      deck.push_back(node->left);
    }
    if(node->right!=NULL){
      deck.push_back(node->right);
    }
  }
};
