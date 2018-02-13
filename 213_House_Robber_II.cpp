#include <iostream>
using namespace std;
/*
  Break the problem into two parts, due to it being a circular array,
  we are free to choose whether we need to rob house 0 or house
  n-1. Just note if we rob house zero we can not rob house n-1. If we
  rob house n-1 we can not rob house n-1.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
      if(nums.size() == 0) return 0;
      if(nums.size() == 1) return nums.back();
      vector<int> amount(nums.size()-1,0);
      vector<int> amount2(nums.size()-1,0);
      //start with robbing the house 0
      amount[0] = nums[0];
      for( int i = 0; i < nums.size()-1; i++){
	if(i == 1){
	  amount[i] = max(nums[0],nums[1]);
	}else{
	  amount[i] = max(amount[i-1],nums[i] + amount[i-2]);
	}
      }
      //robbing the last house
      amount2[0] = nums.back();
      for( int i = 0; i < nums.size()-2;i++){
	if(i == 0){
	  amount2[i+1] = max(nums[i],amount2[i]);
	}else{
	  amount2[i+1] = max(amount2[i], nums[i] + amount2[i-1]);
	}
      }
      return max(amount.back(),amount2.back());
    }
};
