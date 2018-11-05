#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    helper(res, s, 0, 0, '(', ')');
    return res;
  }

  void helper(vector<string> &res, string s, int start_ind_i, int start_ind_j,
              char pre, char post) {
    int prefix = 0;
    for (int i = start_ind_i; i < s.size(); ++i) {
      if (s[i] == pre)
        ++prefix;
      if (s[i] == post)
        --prefix;
      if (prefix >= 0)
        continue;
      for (int j = start_ind_j; j <= i; ++j) {
        if (s[j] == post && (j == start_ind_j || s[j - 1] != post)) {
          helper(res, s.substr(0, j) + s.substr(j + 1), i, j, pre, post);
        }
      }
      return;
    }
    string rev(s.rbegin(), s.rend());
    if (pre == '(')
      helper(res, rev, 0, 0, ')', '(');
    else
      res.push_back(rev);
  }
};

int main() {
  Solution test;
  vector<string> res = test.removeInvalidParentheses(")(");
  cout << endl;
  for (auto s : res)
    cout << s << endl;
}
