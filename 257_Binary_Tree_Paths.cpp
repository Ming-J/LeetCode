#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
};
class Solution{
public:
  void BSF(string path,TreeNode* origin, TreeNode* root, vector<string>& result){
    if(root==NULL){
      return;
    }
    if(origin==root){
      path=to_string(root->val);
    }else{
      path.append("->"+to_string(root->val));
    }
    if(root->left==NULL&&root->right==NULL){
      result.push_back(path);
      return;
    }
    if(root->left!=NULL){
      BSF(path,origin,root->left,result);
    }
    if(root->right!=NULL){
      BSF(path,origin,root->right,result);
    }
  }
  vector<string> binaryTreePaths(TreeNode* root){
    vector<string> result;
    if(root==NULL){
      return result;
    }
    string path;
    BSF(path,root,root,result);
    return result;
  }
};

int main(){
  cout<<"Hello World"<<endl;
}
