#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool isAlienSorted(vector<string> &words, string order) {
    unordered_map<char, int> alpha;
    for (int i = 0; i < order.size(); ++i) {
      alpha.insert(make_pair(order[i], i));
    }
    vector<string> modify = words;
    auto func = [&](string left, string right) {
      for (size_t i = 0; i < left.size() && i < right.size(); ++i) {
        if (left[i] != right[i]) {
          return alpha[left[i]] < alpha[right[i]];
        }
      }
      return left.size() < right.size();
    };
    return is_sorted(modify.begin(), modify.end(), func);
  }
};

int main() {
  vector<string> input = {"hello", "leetcode"};
  string order = "hlabcdefgijkmnopqrstuvwxyz";
  Solution test;
  if (test.isAlienSorted(input, order)) {
    cout << "Y";
  } else {
    cout << "N";
  }
}
