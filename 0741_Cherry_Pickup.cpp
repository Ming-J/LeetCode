#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
  public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(
                       n + 1, vector<int>(n + 1, numeric_limits<int>::min())));
        dp[1][1][1] = grid[0][0];
        for (size_t x1 = 1; x1 < dp.size(); ++x1) {
            for (size_t y1 = 1; y1 < dp.size(); ++y1) {
                for (size_t x2 = 1; x2 < dp.size(); ++x2) {
                    int y2 = x1 + y1 - x2;
                    if (dp[x1][y1][x2] > 0 || y2 >= dp.size() || y2 < 1 ||
                        grid[x1 - 1][y1 - 1] == -1 ||
                        grid[x2 - 1][y2 - 1] == -1)
                        continue;
                    int maxFourDirection = max(
                        dp[x1 - 1][y1][x2],
                        max(dp[x1][y1 - 1][x2], max(dp[x1][y1 - 1][x2 - 1],
                                                    dp[x1 - 1][y1][x2 - 1])));
                    if (maxFourDirection < 0)
                        continue;
                    dp[x1][y1][x2] = maxFourDirection + grid[x1 - 1][y1 - 1];
                    if (x1 != x2) {
                        dp[x1][y1][x2] += grid[x2 - 1][y2 - 1];
                    }
                }
            }
        }
        return dp[n][n][n] < 0 ? 0 : dp[n][n][n];
    }
};

int main() {}