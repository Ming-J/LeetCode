/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
      //struct TreeNode t3(9);
      if(t1==NULL){
      	return t2;
      }
      if(t2==NULL){
	return t1;
      }
      t1->val=t1->val+t2->val;
      t1->left=mergeTrees(t1->left,t2->left);
      t1->right=mergeTrees(t1->right,t2->right);
      return t1;
    }
};

int main(){
  cout<<"Hello World"<<endl;
  struct TreeNode treen1(1);
  treen1.val=1;
  struct TreeNode treen2(2);
  treen2.val=2;
  struct TreeNode treen3(3);
  treen3.val=3;
  struct TreeNode treen4(4);
  treen4.val=4;
  struct TreeNode treen5(5);
  treen5.val=5;
  struct TreeNode treen6(6);
  treen6.val=6;
  treen1.left=&treen2;
  treen2.right=&treen3;
  treen4.left=&treen5;
  treen4.right=&treen6;
  Solution testtree;
  testtree.mergeTrees(&treen1,&treen4);
}
