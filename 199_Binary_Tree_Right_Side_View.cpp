#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
      vector<int> ans;
      if(root==NULL){
	return ans;
      }
      queue<TreeNode*> level;
      level.push(root);
      while(!level.empty()){
	int size=level.size();
	for(int i=0;i<size;i++){
	  TreeNode* temp=level.front();
	  if(i==size-1){
	    ans.push_back(temp->val);
	  }
	  if(temp->left!=NULL){
	    level.push(temp->left);
	  }
	  if(temp->right!=NULL){
	    level.push(temp->right);
	  }
	  level.pop();
	}
      }
      return ans;
    }
};
