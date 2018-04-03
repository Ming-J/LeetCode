#include <iostream>
using namespace std;

class Solution {
public:
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q){
          return root;
        }
        if(root == NULL){
          return NULL;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p , q);
        TreeNode* right = lowestCommonAncestor(root->right, p , q);
        if(left && right) return root;
        //if(left == NULL && right == NULL) return NULL;
        if(left == NULL){
          return right;
        }
        return left;
    }
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
          return NULL;
        }
        bool leftHave = false;
        bool rightHave = false;
        containBoth(root->left,p,q,leftHave,rightHave);
        if(leftHave && rightHave){
          return lowestCommonAncestor1(root->left,p,q);
        }
        leftHave = false;
        rightHave = false;
        containBoth(root->right,p,q,leftHave,rightHave);
        if(leftHave && rightHave){
          return lowestCommonAncestor1(root->right,p,q);
        }
        return root;
    }
    
    void containBoth(TreeNode* root, TreeNode* p, TreeNode* q,bool& cp,bool& cq){
       if(root == NULL){
         return;
       }else{
         if(root==p) cp=true;
         if(root==q) cq=true;
         containBoth(root->left,p,q,cp,cq);
         containBoth(root->right,p,q,cp,cq);
       }    
    }
  
};
