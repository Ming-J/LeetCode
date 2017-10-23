#include <stack>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> ans;
      if(root==NULL){return ans;}
      stack<TreeNode*> deck;
      TreeNode* cur=root;
      deck.push(root);
      while(!deck.empty()){
	if(cur->left!=NULL){
	  deck.push(cur->left);
	  cur=cur->left;
	}else{
	  cur=deck.top();
	  deck.pop();
	  ans.push_back(cur->val);
	  if(cur->right!=NULL){
	    cur=cur->right;
	  }
	}
      }
      return ans;
    }
};
