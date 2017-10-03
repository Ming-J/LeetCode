#include <iostream>
#include <queue>
#include <vector>
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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int depth=checkdepth(root);
    vector<int> temp;
    vector< vector<int> > result(depth,temp);
    if(root==NULL){
      return result;
    }
    queue<TreeNode*> level;
    level.push(root);
    depth--;
    while(!level.empty()){
      int n=level.size();
      vector<int> row;
      for(int i=0;i<n;i++){
	TreeNode* cur=level.front();
	row.push_back(cur->val);
	level.pop();
	if(cur->left!=NULL){
	  level.push(cur->left);
	}
	if(cur->right!=NULL){
	  level.push(cur->right);
	}
      }
      result[depth--]=row;
    }
    return result;
  }
  int checkdepth(TreeNode* root){
    if(root==NULL){
      return 0
    }
    return 1+max(checkdepth(root->left),checkdepth(root->right));
  }
};
