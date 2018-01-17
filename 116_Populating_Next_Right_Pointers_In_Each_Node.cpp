#include <iostream>
using namespace std;

/*
Just like the Level order, make sure use of the next pointer
*/

//Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
      if(root==NULL){
	return;
      }

      while(root){
	TreeLinkNode* lvStart=root->left;
	for(;root!=NULL;root=root->next){
	  if(root->left!=NULL&&root->right!=NULL){
	    root->left->next = root->right;
	    if(root->next){
	      root->right->next = root->next->left;
	    }else{
	      root->right->next = NULL;
	    }
	  }
	}
	root = lvStart;
      }
    }
};
