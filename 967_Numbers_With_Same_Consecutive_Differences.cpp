#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> ans;
    for (int i = 0; i < 10; ++i) {
      helper(ans, N, K, i, i, 1);
    }
    return ans;
  }

  void helper(vector<int> &ans, int N, int K, int val, int last, int n) {
    if (N == n) {
      cout << val << endl;
      if (to_string(val).size() == N)
        ans.push_back(val);
      return;
    }
    for (int i = 0; i < 10; ++i) {
      if (abs(last - i) == K) {
        helper(ans, N, K, val * 10 + i, i, n + 1);
      }
    }
  }
};

int main() {
  Solution t;
  t.numsSameConsecDiff(2, 1);
}
