#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int closest = INT_MAX;
    int resSum;
    for(size_t i = 0; i < nums.size() - 2; ++i){
      int lo = i+1;
      int hi = nums.size() - 1;
      while(lo<hi){
	int sum = nums[i] + nums[lo] + nums[hi];
	if(abs(target - sum) < closest){
	  closest = abs(target - sum);
	  resSum = sum;
	}
	closest = min(closest,abs(target - sum));
	if(sum > target){x
	  --hi;
	}else{
	  ++lo;
	}
      }
    }
    return resSum;
  }
};
