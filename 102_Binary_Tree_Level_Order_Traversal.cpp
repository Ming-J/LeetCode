/*===================================================== 

102 Binary Tree Level Travesal Given a binary tree, return the level
order traversal of its nodes' values. (ie, from left to right, level
by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]


Time Complexity:O(N)
Space Complexity:O(N)

Using queue to slove this problem
1. Create empty queue q
2. Set Temp Node to root
3  Loop through while temp node is not NULL
   a. Print data
   b. Enqueue temp node children
   c. Dequeue a node from q and assign it to temp Node
 ======================================================*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution{
  public:
  vector< vector<int> > levelOrder(TreeNode* root) {
    vector< vector<int> > result;
    if (root==NULL){
      return result;
    }
    vector<int> rows;
    pair <TreeNode*, int> currentset(root,0);
    queue<pair<TreeNode*,int> > deck;
    int currentdepth=0;
    deck.push(currentset);
    while(!deck.empty()){
      deck.pop();
      if(currentset.second!=currentdepth){
	result.push_back(rows);
	rows.erase(rows.begin(),rows.end());
	currentdepth=currentset.second;
      }
      rows.push_back(currentset.first->val);
      if(currentset.first->left!=NULL){
	pair <TreeNode*, int> newset(currentset.first->left, currentset.second+1);
	deck.push(newset);
      }
      if(currentset.first->right!=NULL){
	pair <TreeNode*, int> newset(currentset.first->right, currentset.second+1);
	deck.push(newset);
      }
      if(!deck.empty()){
	currentset=deck.front();
      }
      cout<<currentset.first->val<<" "<<currentset.second<<endl;
    }
    result.push_back(rows);
    return result;
  }
};


int main(){
  cout<<"Helloe World"<<endl;
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
  treen1.right=&treen4;
  treen2.right=&treen3;
  treen4.left=&treen5;
  treen4.right=&treen6;
  Solution testtree;
  vector< vector<int> > result;
  result=testtree.levelOrder(&treen1);
  cout<<endl;
  for(int i=0;i<result.size();i++){
    for(int j=0;j<result[i].size();j++){
      cout<<result[i][j];
    }
    cout<<endl;
  }
}
