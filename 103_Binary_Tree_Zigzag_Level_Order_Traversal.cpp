#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
      vector<vector<int> > result;
      if(root==NULL){
	return result;
      }
      deque<TreeNode*> temp;
      int rowNumber=1;
      temp.push_back(root);
      while(!temp.empty()){
	vector<int> row;
	int rowSize=temp.size();
	if(rowNumber%2==0){
	  for(int i=0;i<rowSize;i++){
	    TreeNode* behind=temp.back();
	    row.push_back(behind->val);
	    temp.pop_back();
	    if(behind->right!=NULL){
	      temp.push_front(behind->right);
	    }
	    if(behind->left!=NULL){
	      temp.push_front(behind->left);
	    }
	  }
	}else{
	  for(int i=0;i<rowSize;i++){
	    TreeNode* front=temp.front();
	    row.push_back(front->val);
	    temp.pop_front();
	    if(front->left!=NULL){
	      temp.push_back(front->left);
	    }
	    if(front->right!=NULL){
	      temp.push_back(front->right);
	    }
	  }
	}
	result.push_back(row);
	rowNumber++;
	}
      return result;
    } 
};
