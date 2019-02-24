
#include <iostream>
#include <map>
#include <set>
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
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    map<int, map<int, set<int>>> _map;
    helper(_map, 0, 0, root);
    vector<vector<int>> ans;
    for (auto x_p : _map) {
      vector<int> vert;
      for (auto y_p : x_p.second) {
        vert.insert(vert.end(), y_p.second.begin(), y_p.second.end());
      }
      ans.push_back(vert);
    }
    return ans;
  }

private:
  void helper(map<int, map<int, set<int>>> &_map, int x, int y,
              TreeNode *node) {
    if (node == NULL)
      return;
    _map[x][y].insert(node->val);
    helper(_map, x - 1, y + 1, node->left);
    helper(_map, x + 1, y + 1, node->right);
  }
};