#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode{
  int val;
  bool isOr;
  TreeNode* left;
  TreeNode* right;
  TreeNode* parent;
  TreeNode(int v,bool f):val(v),isOr(f),left(NULL),right(NULL),parent(NULL){}
};


class Xenia{
public:
  Xenia(vector<int> input){
    queue<TreeNode*> que;
    for(size_t i = 0; i < input.size(); ++i){
      TreeNode* temp = new TreeNode(input[i],true);
      seq.push_back(temp);
      que.push(temp);
    }
    while(que.size() != 1){
      int size = que.size();
      for(int i = 0; i < size; i+=2){
	TreeNode* left = que.front();
	que.pop();
	TreeNode* right = que.front();
	que.pop();
	TreeNode* par;
	if(left->isOr){
	  par = new TreeNode(left->val|right->val,!left->isOr);
	}else{
	  par = new TreeNode(left->val^right->val,!left->isOr);
	}
	par->left = left;
	par->right = right;
	left->parent = par;
	right->parent = par;
	que.push(par);
      }
    }
    root = que.front();
    //cout<<root->val<<endl;
  }

  int change(int index, int newVal){
    TreeNode* change = seq[index-1];
    change->val = newVal;
    while(change->parent!=NULL){
      //cout<<change->val<<endl;
      change = change->parent;
      if(change->isOr)change->val=change->left->val^change->right->val;
      else change->val=change->left->val|change->right->val;
    }
    return root->val;
  }
  
  void deleteRec(TreeNode* root){
    if(root){
      deleteRec(root->left);
      deleteRec(root->right);
      delete root;
    }
  }
  ~Xenia(){
    //deleteRec(root);
  }
private:
  TreeNode* root;
  vector<TreeNode*> seq;
};


int main(){
  int n, m;
  cin>>n>>m;
  vector<int> input(pow(2,n));
  for(auto& i : input) cin>>i;  
  Xenia h(input);
  for(int i = 0; i < m; ++i){
    int p,q;
    cin>>p>>q;
    cout<<h.change(p,q)<<endl;
  }
  
}
