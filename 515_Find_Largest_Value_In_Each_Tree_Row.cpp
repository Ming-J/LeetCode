#include <iostream>
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
  vector<int> largestValues(TreeNode* root){
    vector<int> output;
    vector<TreeNode*> nodearr;
    if(root==NULL){
      return output;
    }else{
      nodearr.push_back(root);
    }
    while(!nodearr.empty()){
      int max=nodearr[0]->val;
      vector<TreeNode*> newarr;
      for(int i=0;i<nodearr.size();i++){
	TreeNode *now=nodearr[i];
	if(now->val>max){
	  max=now->val;
	}
 	if(now->left!=NULL){
	  newarr.push_back(now->left);
	}
	if(now->right!=NULL){
	  newarr.push_back(now->right);
	}
      }
      output.push_back(max);
      nodearr=newarr;
    }
    return output;
  }
};

int main(){
  cout<<"Hello World"<<endl;
}
