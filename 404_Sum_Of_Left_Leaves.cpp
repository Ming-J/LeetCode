/*===============================================================

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15
respectively. Return 24.

Do a normal traversal. And by having a helper fuction. We are able to
pass in a paremeter to know if the current node is a left leaves. If
it is a left leaves and has no children leave. Then we add the sum.


================================================================*/

#include <iostream>
using namespace std;

struct TreeNode{
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  int sumOfLeftLeaves(TreeNode* root){
    if(root==NULL){
      return 0;
    }

    int total=0;
    sumLeftLeaves(root,false,total);
    return total;
  }

  void sumLeftLeaves(TreeNode* root, bool isleft, int& sum){
    if(root==NULL){
      return;
    }
    sumLeftLeaves(root->left,true,sum);  // Passing true for left leaves
    if(isleft==true&&root->left==NULL&&root->right==NULL){  
      sum=sum+root->val; // add value if the current leave has no children and is a leftleave
    }
    sumLeftLeaves(root->false,0,sum); //passing false for right leaves
  }
  
};


int main(){
  return 0;
}
