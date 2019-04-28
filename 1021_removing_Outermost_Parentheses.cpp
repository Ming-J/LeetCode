#include <iostream>
using namespace std;

class Solution {
public:
  string removeOuterParentheses(string S) {
    int open = 0, close = 0;
    string res;
    for (size_t i = 0; i < S.size(); ++i) {
      if (S[i] == '(')
        ++open;
      else
        ++close;
      if (open == close) {
        string sub = S.substr(i + 2 - open - close, open + close - 2);
        open = 0, close = 0;
        res += sub;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  s.removeOuterParentheses("((()))()()(()())");
  return 0;
}
