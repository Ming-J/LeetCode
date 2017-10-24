#include <stack>
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
/*inorder traversal not using recursion using stack
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> ans;
      if(root==NULL){return ans;}
      stack<TreeNode*> deck;
      TreeNode* cur=root;
      while(!deck.empty()||cur){
	if(cur!=NULL){
	  deck.push(cur);
	  cur=cur->left;
	}else{
	    cur=deck.top();
	    ans.push_back(cur->val);
	    deck.pop();
	    cur=cur->right;
	}
      }
      return ans;
    }
};
