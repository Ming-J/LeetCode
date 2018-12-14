#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int tallestBillboard(vector<int> &rods) {
    int sum = accumulate(rods.begin(), rods.end(), 0);
    return dp(rods, sum);
  }

  int dp(vector<int> &rods, int sum) {
    vector<vector<int>> ss(rods.size() + 1, vector<bool>(sum + 1, 0));
    for (auto &row : ss)
      row[0] = 1;
    for (size_t i = 1; i <= rods.size(); ++i) {
      for (size_t j = 0; j <= sum; ++j) {
        if (j < rods[i - 1])
          ss[i][j] = ss[i - 1][j];
        else {
          ss[i][j] = ss[i - 1][j] || ss[i - 1][j - rods[i - 1]];
        }
      }
    }
    int ans = 0;
    for (size_t j = sum; j <= sum; --j) {
      if (ss.back()[j] && j % 2 == 0 && ss.back()[j / 2])
        return j / 2;
    }
    return 0;
  }
};

int main() {
  vector<int> input = {1, 2};
  Solution test;
  cout << test.tallestBillboard(input) << endl;
}
