#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValid(string S) {
    vector<char> s_;
    for (char c : S) {
      s_.push_back(c);
      while (s_.size() >= 3 && s_[s_.size() - 1] == 'c' &&
             s_[s_.size() - 2] == 'b' && s_[s_.size() - 3] == 'a') {
        s_.pop_back();
        s_.pop_back();
        s_.pop_back();
      }
    }
    return s_.empty();
  }
};
