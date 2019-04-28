#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int videoStitching(vector<vector<int>> &clips, int T) {
    vector<vector<int>> dp(T + 1,
                           vector<int>(T + 1,101 ));
    for (auto clip : clips) {
      int st = clip[0];
      int ed = clip[1];
      for (int len = 1; len <= T; ++len) {
        for (int i = 0; i <= T - len; ++i) {
          int j = i + len;
          if (st > j || ed < i)
            continue;
          else if (st < i && j < ed)
            dp[i][j] = 1;
          else if (st > i && j > ed)
            dp[i][j] = min(dp[i][j], dp[i][st] + 1);
          else if (st < i && ed < j)
            dp[i][j] = min(dp[i][j], dp[ed][j] + 1);
          else
            dp[i][j] = min(dp[i][j], dp[i][st] + 1 + dp[ed][j]);
        }
      }
    }
    return dp[0][T];
  }
};

int main() {
  Solution t;
  // t.videoStitching();
  cout << "H" << endl;
}
