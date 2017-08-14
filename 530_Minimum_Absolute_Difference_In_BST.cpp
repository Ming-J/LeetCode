#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  int getMinimumDifference(TreeNode* root){
    int min=INT_MAX;
    TreeNode* pre=NULL;
    inOrder(root,pre,min);
    return min;
  }

  void inOrder(TreeNode* root,TreeNode*& previous,int& min){
    if(root->left!=NULL){
      //min=fmin(min,abs(root->val-root->left->val));
      inOrder(root->left,previous,min);
    }
    // cout<<root->val<<" "<<previous->val<<endl;
    if(previous!=NULL){
      min=fmin(min,abs(root->val-previous->val));
    }
    previous=root;
    if(root->right!=NULL){
      //min=fmin(min,abs(root->val-root->right->val));
      inOrder(root->right,previous,min);
    }
  }
};

int main(){
  cout<<"Hello World"<<endl;
}
