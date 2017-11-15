#include <iostream>
#include <deque>
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
    int widthOfBinaryTree(TreeNode* root) {
      int maxwidth=0;
      if(root==NULL) return maxwidth;
      deque<pair<TreeNode*,int> > level;
      level.push_back(make_pair(root,1));
      while(!level.empty()){
	int width=level.size();
	maxwidth=max(maxwidth,level.back().second-level.front().second);
	for(int i=0;i<width;i++){
	  TreeNode* cur=level.front().first;
	  int nodeN=level.front().second;
	  if(cur->left!=NULL){
	    level.push_back(make_pair(cur->left,nodeN*2));
	  }
	  if(cur->right!=NULL){
	    level.push_back(make_pair(cur->right,nodeN*2+1));
	  }
	  level.pop_front();
	}
      }
      return maxwidth;
    }

  int calculateWidth(deque<TreeNode*> level){
    while(level.front()==NULL&&!level.empty()){
      level.pop_front();
    }
    while(level.back()==NULL&&!level.empty()){
      level.pop_back();
    }
    return level.size();
  }
      
};
