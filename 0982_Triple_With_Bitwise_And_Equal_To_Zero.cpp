#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int countTriplets(vector<int> &A) {
        vector<vector<int>> dp(3, vector<int>(1 << 16, 0));
        for (int a : A) {
            ++dp[0][a];
        }
        for (size_t i = 1; i < dp.size(); ++i) {
            for (size_t j = 0; j < dp[i].size(); ++j) {
                if (dp[i - 1][j] != 0) {
                    for (int a : A) {
                        dp[i][j & a] += dp[i - 1][j];
                    }
                }
            }
        }
        return dp[2][0];
    }

  private:
};

int main() {
    vector<int> input = {1, 2, 3};
    Solution t;
    cout << t.countTriplets(input) << endl;
    cout << (1 << 16) << endl;
    ;
}