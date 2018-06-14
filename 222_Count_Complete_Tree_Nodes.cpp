#include <iostream>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Use regular traversal, we got an Time Limit Exceeded


class Solution {
public:
  int countNodes(TreeNode* root) {
    //Boundry check to see if root is valid
    if(root == NULL) return 0;
    //checking the left most node depth and right most depth
    int depthL = 0, depthR = 0;
    for(TreeNode* tempL = root; tempL != NULL; tempL=tempL->left,++depthL){}
    for(TreeNode* tempR = root; tempR != NULL; tempR=tempR->right,++depthR){}
    //if the depth of left and right are the same, we can say it's a
    //complete tree
    if(depthL == depthR) return (1<<depthL)- 1;
    //else get the count of left child and right child plus it's self
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
