#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
  int jump(vector<int>& nums) {
    if(nums.size() <= 1) return 0;
    vector<int> dp(nums.size(),numeric_limits<int>::max());
    dp[0] = 0;
    for(int i = 0; i < nums.size(); ++i){
      int maxStep = nums[i];
      for(int j = 1; i+j < nums.size() && j <= maxStep; ++j){
	dp[i+j] = min(dp[i]+1,dp[i+j]); 
      }
    }
    return dp.back();
  }
};
