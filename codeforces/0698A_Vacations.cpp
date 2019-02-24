#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
/*
  0: gym closed, contest closed
  1: gym closed, contest open
  2: gym is open, contest is not open
  3: gym open, contest open
  if 0 is R

  1 3 2 0
  C G R R
*/

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(3, vector<int>(n + 1, numeric_limits<int>::max()));
    dp[0][0] = 0;
    // dp[0][] rest   dp[1][] gym   dp[2][] contest
    for (size_t i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        dp[0][i] = min(dp[0][i - 1], min(dp[1][i - 1], dp[2][i - 1])) + 1;
        if (t == 1) // contest is open
            dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]);
        if (t == 2) // gym is open
            dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]);
        if (t == 3) { // contest is open,, gym is open
            dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]);
            dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]);
        }
    }
    cout << min(dp[0][n], min(dp[1][n], dp[2][n])) << endl;
    return 0;
}
