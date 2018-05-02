#include <iostream>
using namespace std;

class Solution {
public:
  int dominantIndex(vector<int>& nums) {
    if(nums.size() == 1) return 0;
    int maxVal = -1;
    int index = -1;
    int twiceVal = 0;
    for(size_t i = 0; i < nums.size(); ++i){
      if(maxVal < nums[i]){
	twiceVal = max(twiceVal,maxVal * 2);
	maxVal = nums[i];
	index = i;
      }else{
	twiceVal = max(twiceVal,nums[i] * 2);
      }
    }
    return  maxVal >= twiceVal ? index : -1;
  }
};
