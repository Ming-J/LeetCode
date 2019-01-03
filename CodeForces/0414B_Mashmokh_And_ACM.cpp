#include <iostream>
#include <numeric>
#include <vector>
#define MOD 1000000007;
using namespace std;

int main() {
  int n = 1478;
  int m = 194;
  cin >> n >> m;
  vector<vector<long>> dp(m + 1, vector<long>(n + 1));
  for (size_t i = 0; i < dp.front().size(); ++i) {
    dp[1][i] = 1;
  }
  for (size_t i = 2; i < dp.size(); ++i) {
    for (size_t j = 1; j < dp[i].size(); ++j) {
      for (size_t z = j; z < dp[i].size(); z += j) {
        dp[i][z] += dp[i - 1][j];
        dp[i][z] %= MOD;
      }
    }
  }
  auto func = [](unsigned long long int left, long right) {
    left += right;
    return left %= MOD;
  };
  cout << accumulate(dp.back().begin() + 1, dp.back().end(),
                     (unsigned long long int)0, func)
       << endl;
}
