#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root=BSTHelper(nums,0,nums.size()-1);
    return root;
  }
  TreeNode* BSTHelper(vector<int>& nums, int lo, int hi){
    if(hi>=lo){
      int mid=lo+(hi-lo)/2;
      TreeNode* root= new TreeNode(nums[mid]);
      root->left=BSTHelper(nums,lo,mid-1);
      root->right=BSTHelper(nums,mid+1,hi);
      return root;
    }
    return NULL;
  }
};
