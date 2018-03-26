#include <iostream>
#include <queue>
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
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if(root==NULL) return NULL;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
      size_t level = q.size();
      --d;
      for(size_t i = 0; i < level; ++i){
	TreeNode* cur = q.front();
	if(cur->left != NULL){
	  if(d==0){
	    TreeNode* addition = new TreeNode(v);
	    addition->left = cur->left;
	    cur->left = addition;
	  }
	  q.push(cur->left);
	}
	if(cur->right != NULL){
	  if(d==0){
	    TreeNode* addition = new TreeNode(v);
	    addition->right = cur->right;
	    cur->right = addition;
	  }
	  q.push(cur->right);
	}
	q.pop();
      }
    }
    return root;
  }
};
