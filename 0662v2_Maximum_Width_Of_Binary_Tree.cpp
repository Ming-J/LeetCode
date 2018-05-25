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
//Since we are able to represent the tree in an array with index
// value.  We can have it's left children I*2 and right children i*2 +
// 1 with the index val and using BFS, we can figure out the width for
// the level.
class Solution{
public:
  int widthOfBinaryTree(TreeNode* root){
    if(root == NULL) return 0;
    queue< pair<TreeNode*,int> > q;
    q.push(make_pair(root,1)); //Starting with Index value 1
    int maxWidth = INT_MIN;
    while(!q.empty()){
      maxWidth = max(maxWidth,q.back().second-q.front().second+1);
      int width = q.size();
      for(size_t i = 0; i < width; ++i ){
	TreeNode* cur = q.front().first;
	int curIndex = q.front().second;
	q.pop();
	//Left child 2*i
	if(cur->left) q.push(make_pair(cur->left,curIndex*2));
	//right child 2*i+1
	if(cur->right) q.push(make_pair(cur->right,curIndex*2+1));
      }
    }
    return maxWidth;
  }
};
