#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxCoins(vector<int> &nums) {
    int dp[nums.size()][nums.size()] = 0;
    for (size_t len = 0; len < nums.size(); ++len) {
      for (size_t left = 0; left < nums.size() - len; ++left) {
        size_t right = left + len;
        cout << "L and R: " << left << ' ' << right << endl;
        for (size_t i = left; i <= right; ++i) {
          int left_coin = (left > 0) ? nums[left - 1] : 1;
          int right_coin = (right + 1 < nums.size()) ? nums[right + 1] : 1;
          int left_dp = (i > 0) ? dp[left][i - 1] : 0;
          int right_dp = (i + 1 < nums.size()) ? dp[i + 1][right] : 0;
          dp[left][right] =
              max(dp[left][right],
                  (left_coin * nums[i] * right_coin) + left_dp + right_dp);
        }
      }
    }
    int coins = 0;
    helper(nums, 0, coins);
    cout << coins << ' ' << dp[0].back() << endl;
    return coins;
  }

private:
  void helper(vector<int> nums, int cur_max, int &final_max) {
    if (nums.size() == 0) {
      final_max = (cur_max > final_max) ? cur_max : final_max;
      return;
    }
    if (nums.size() == 1) {
      helper(vector<int>(), cur_max + nums.front(), final_max);
    } else if (nums.size() == 2) {
      int prod = nums.front() * nums.back();
      helper(vector<int>(nums.begin() + 1, nums.end()), cur_max + prod,
             final_max);
      helper(vector<int>(nums.begin(), nums.end() - 1), cur_max + prod,
             final_max);
    } else {
      helper(vector<int>(nums.begin() + 1, nums.end()),
             cur_max + (nums[0] * nums[1]), final_max);
      for (size_t i = 1; i < nums.size() - 1; ++i) {
        vector<int> temp = nums;
        int temp_sum = nums[i] * nums[i - 1] * nums[i + 1];
        temp.erase(temp.begin() + i);
        helper(temp, cur_max + temp_sum, final_max);
      }
      helper(vector<int>(nums.begin(), nums.end() - 1),
             cur_max + (nums[nums.size() - 2] * nums[nums.size() - 1]),
             final_max);
    }
  }
};

int main() {
  vector<int> co = {7, 9, 8, 0, 7, 1, 3, 5, 5, 2, 3};
  // vector<int> co = {3, 1, 5, 8};
  Solution t;
  cout << t.maxCoins(co) << endl;
}