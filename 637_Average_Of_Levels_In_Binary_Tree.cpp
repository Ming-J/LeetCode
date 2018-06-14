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
    vector<double> averageOfLevels(TreeNode* root) {
      // level order traversal, using queue
      vector<double> avg;
      if(root == NULL) return avg;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
	size_t size = q.size();
	double sum = 0;
	for(size_t i = 0; i < size; ++i){
	  TreeNode* cur =  q.front();
	  q.pop();
	  sum += cur->val;
	  if(cur->left != NULL) q.push(cur->left);
	  if(cur->right != NULL) q.push(cur->right);
	}
	avg.push_back(sum/size);
      }
      return avg;
    }
};
