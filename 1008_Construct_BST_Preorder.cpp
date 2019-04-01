#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    if (preorder.empty())
      return NULL;
    TreeNode *root = new TreeNode(preorder.front());
    stack<TreeNode *> _s;
    _s.push(root);
    for (size_t i = 1; i < preorder.size(); ++i) {
      TreeNode *cur = new TreeNode(preorder[i]);
      if (cur->val < _s.top()->val) {
        _s.top()->left = cur;
      } else {
        TreeNode *last = _s.top();
        _s.pop();
        while (!_s.empty() && cur->val > _s.top()->val) {
          last = _s.top();
          _s.pop();
        }
        last->right = cur;
      }
      _s.push(cur);
    }
    return root;
  }
};

int main() { cout << "H" << endl; }
