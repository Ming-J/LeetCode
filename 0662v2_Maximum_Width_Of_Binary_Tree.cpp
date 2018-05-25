#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  int widthOfBinaryTree(TreeNode* root){
    if(root == NULL) return 0;
    queue< pair<TreeNode*,int> > q;
    q.push(make_pair(root,1));
    int maxWidth = INT_MIN;
    while(!q.empty()){
      maxWidth = max(maxWidth,q.back().second-q.front().second+1);
      int width = q.size();
      for(size_t i = 0; i < width; ++i ){
	TreeNode* cur = q.front().first;
	int curIndex = q.front().second;
	q.pop();
	if(cur->left) q.push(make_pair(cur->left,curIndex*2));
	if(cur->right) q.push(make_pair(cur->right,curIndex*2+1));
      }
    }
    return maxWidth;
  }
};
