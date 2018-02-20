#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp=cost;
    for(size_t i = 0; i < cost.size(); i++){
      if(i == 0 || i ==2){
	dp[i] = cost[i];
      }else{
	dp[i] = min(dp[i-1], dp[i-2]) + cost[i]; 
      }
    }
    return min(dp[dp.size()-1], dp[dp.size()-2]);
  }
};
