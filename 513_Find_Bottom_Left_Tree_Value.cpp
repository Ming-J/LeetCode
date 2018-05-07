#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int leftMost;
    while(!q.empty()){
      int size = q.size();
      leftMost = q.front()->val;
      for(int i = 0; i < size; ++i){
	TreeNode* cur = q.front();
	q.pop();
	if(cur->left != NULL){
	  q.push(cur->left);
	}
	if(cur->right != NULL){
	  q.push(cur->right);
	}
      }
    }
    return leftMost;
  }
};
