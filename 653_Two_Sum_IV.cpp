#include <iostream>
#include <vector>
#include <stack>
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
    bool findTarget(TreeNode* root, int k) {
      if(root==NULL){return false;}
      vector<int> arr;
      stack<TreeNode*> deck;
      while(root||!deck.empty()){
	if(root){
	  deck.push(root);
	  root=root->left;
	}else{
	  root=deck.top();
	  deck.pop();
	  arr.push_back(root->val);
	  root=root->right;
	}
      }
      int j=arr.size()-1;
      for(int i=0;i<j;){
	int sum=arr[i]+arr[j];
	if(sum==k){
	  return true;
	}else{
	  if(sum>k){
	    j--;
	  }else{
	    i++;
	  }
	}
      }
      return false;
    }
};
