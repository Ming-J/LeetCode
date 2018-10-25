#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int maxSubArray(vector<int>& nums){
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int sum = dp[0];
    for(size_t i = 1; i < nums.size(); ++i){
      dp[i] = ((dp[i-1] > 0)? dp[i-1] : 0)+nums[i];
      sum = max(sum,dp[i]);
    }
    return sum;
  }
};
