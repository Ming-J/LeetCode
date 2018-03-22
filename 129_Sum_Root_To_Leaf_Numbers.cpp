#include <iostream>
#include <queue>
using namespace std;
/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf
path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the
number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
 */
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int sumNumbers(TreeNode* root) {
    if(root == NULL) return 0;
    int sum = 0;
    queue<pair<TreeNode*,int> > q;
    q.push(make_pair(root,root->val));
    while(!q.empty()){
      int lsize = q.size();
      for(int i = 0; i < lsize; ++i){
	pair<TreeNode*, int> c = q.front();
	q.pop();
	if(c.first->left == NULL && c.first->right == NULL){
	  sum += c.second;
	}else{
	  if(c.first->left != NULL){
	    q.push(make_pair(c.first->left,c.second*10+c.first->left->val));
	  }
	  if(c.first->right != NULL){
	    q.push(make_pair(c.first->right,c.second*10+c.first->right->val));
	  }
	}
      }
    }
    return sum;
  }
};
