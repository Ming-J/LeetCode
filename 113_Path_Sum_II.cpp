#include <iostream>
#include <vector>
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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
      vector<vector<int> >result;
      vector<int> path;
      int csum=0;
      if(root==NULL){
	return result;
      }
      preorder(result,path,csum,sum,root);
      return result;
    }
  void preorder(vector< vector<int> > &ans,vector<int> path,
		int csum,int sum, TreeNode* root){
    if(root==NULL){
      return;
    }
    csum+=root->val;
    path.push_back(root->val);
    if(root->left==NULL&&root->right==NULL){
      if(csum==sum){
	ans.push_back(path);
      }
    }else{
      preorder(ans,path,csum,sum,root->left);
      preorder(ans,path,csum,sum,root->right);
    }
    return;
  }
};
