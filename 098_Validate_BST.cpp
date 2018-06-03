
struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  bool isValidBST(TreeNode* root){
    bool valid = true;
    long prev = LONG_MIN;
    isValid(root,prev,valid);
    return valid;
  }
  void isValid(TreeNode* node, long& prev, bool& valid){
    if(node == NULL) return;
    isValid(node->left,prev,valid);
    if(node->val <= prev){
      valid = false;
    }
    prev = node->val;
    isValid(node->right,prev,valid);
  }
};
