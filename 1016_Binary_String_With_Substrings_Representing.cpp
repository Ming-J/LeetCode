#include <cmath>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool queryString(string S, int N) {
    unordered_set<int> nums;
    for (size_t i = 1; i <= S.size() && i <= 20; ++i) {
      for (size_t j = 0; j <= S.size() - i; ++j) {
        nums.insert(convert(S.substr(j, i)));
      }
    }
    for (int i = 1; i <= N; ++i) {
      if (nums.find(i) == nums.end())
        return false;
    }
    return true;
  }

  int convert(string str) {
    int n = 0;
    for (size_t i = 0, j = str.size() - 1; i < str.size(); ++i, --j) {
      if (str[i] == '1')
        n += pow(2, j);
    }
    return n;
  }
};

int main() {
  Solution t;
  t.queryString("asda", 4);
  cout << "Hello" << endl;
}
