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
      vector<int> rows;
      pair <TreeNode*, int> currentset(root,0);
      queue<pair<TreeNode*, int> > deck;
      int currentdepth=0;
      do{
	if(currentset.second!=currentdepth){
	  result.push_back(rows);
	  rows.erase(rows.begin(),rows.end());
	}
       	rows.push_back(currentset.first->val);
	if(currentset.first->left!=NULL){
	  currentset=make_pair(currentset.first->left, currentset.second+1);
	  deck.push(currentset);
	}
	if(currentset.first->right!=NULL){
	  currentset=make_pair(currentset.first->right, currentset.second+1);
	  deck.push(currentset);
	}
	currentset=deck.front();
	deck.pop();
      }
      while(!deck.empty());
      return result;
    }
};


int main(){
  cout<<"Helloe World"<<endl;
}
