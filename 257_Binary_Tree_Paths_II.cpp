#include <vector>
#include <iostream>
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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(root == NULL ) return res;
    help(res,"",root);
    return res;
  }

  void helper(vector<string>& res, string path, TreeNode* node){
      path += (path.empty())?to_string(node->val):"->"+to_string(node->val);
      if(node->left) helper(res,path,node->left);
      if(node->right) helper(res,path,node->right);
      if(!node->left&&!node->right) res.push_back(path);
  }
};
