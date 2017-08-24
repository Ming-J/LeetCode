#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  void preorder(TreeNode *root, vector<int>& result){
    if(root==NULL){
      return;
    }
    result.push_back(root->val);
    preorder(root->left,result);
    preorder(root->right,result);
  }
  
  vector<int> preorderTraversal(TreeNode* root){
    vector<int> result;
    preorder(root, result);
    return result;
  }
};

class iteratively{
public:
  vector<int> preorderTraversal(TreeNode* root){
    vector<int> traversal;
    if(root==NULL){
      return traversal;
    }
    stack<TreeNode*> nodestack;
    nodestack.push(root);
    while(!nodestack.empty()){
      TreeNode* temp=nodestack.top();
      nodestack.pop();
      traversal.push_back(temp->val);
      if(temp->right!=NULL){
      	nodestack.push(temp->right);
      }
      if(temp->left!=NULL){
	nodestack.push(temp->left);
      }
    }
    return traversal;
  }
};

int main(){
  cout<<"Hello World"<<endl;
  TreeNode one(1);
  TreeNode two(2);
  one.left=&two;
  iteratively test;
  vector<int> result;
  result=test.preorderTraversal(&one);
  for(int i=0;i<result.size();i++){
    cout<<result[i]<<" ";
  }
}
