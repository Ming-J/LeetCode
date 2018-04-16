#include <iostream>
#include <vector>
using namespace std;
/*
  Can use the hash table.
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
  vector<int> findMode(TreeNode* root) {
    vector<int> ans;
    int preVal = INT_MAX;
    int maxCount = 0;
    int curCount = 0;
    inOrder(root,ans,preVal,maxCount,curCount);
    return ans;
  }
  void inOrder(TreeNode* root,vector<int>& ans,int &prevVal, int &maxCount,int &curCount){
    if(root == NULL) return;
    inOrder(root->left,ans,prevVal,maxCount,curCount);
    curCount = prevVal == root->val ? curCount+1 : 1;
    if(curCount >= maxCount){
      if(curCount > maxCount) ans.clear();
      ans.push_back(root->val);
      maxCount = curCount;
    }
    prevVal = root->val;
    inOrder(root->right,ans,prevVal,maxCount,curCount);
  }
};

int main(){
  TreeNode* one = new TreeNode(1);
  TreeNode* two = new TreeNode(2); 
  TreeNode* two2 = new TreeNode(2);
  one->right = two;
  two->left = two2;
  Solution test;
  vector<int> result = test.findMode(one);
  for(auto v : result){
    cout<<v<<endl;
  }
}
