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
  bool isBalanced(TreeNode* root) {
    if(root==NULL){  // return tree cus the difference are zero
      return true;
    }  //checking if the height of left and right sub tree are within 1, return false if not
    if(abs(balanceHelper(root->left)-balanceHelper(root->right))>1){
      return false;
    }//continue checking each node in the tree
    return isBalanced(root->left)&&isBalanced(root->right); 
  }
  //Helper function to help find the height of a given tree
  int balanceHelper(TreeNode* root){
    if(root==NULL){
      return 0;
    }else{
      return 1+max(balanceHelper(root->left),balanceHelper(root->right));
    }
  }
};

//Could do a bottom up approach to avoid necessary search
class Solution2{
  bool isBalanced(TreeNode* root){
    if(dfs(root)==-1){
      return false;
    }else{
      return true;
    }
  }
  int dfs(TreeNode* root){
    if(root==NULL){
      return 0;
    }
    int leftH=dfs(root->left);
    if(leftH==-1){return -1;}
    inr rightH=dfs(root->right);
    if(rightH==-1){return -1;}

    if(abs(leftH-rightH)>1){
      return -1;
    }else{
      return max(leftH,rightH)+1;
    }
  }
};
