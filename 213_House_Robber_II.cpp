#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
      vector<int> amount(nums.size(),0);
      for( int i = 0; i < nums.size(); i++){
	if( i == 0 ){
	  amount[i] = nums[0];
	}else if(i == 1){
	  amount[i] = max(nums[0],nums[1]);
	}else{
	  amount[i] = max(amount[i-1],nums[i] + amount[i-2]);
	}
      }
      return amount[nums.size()-1];
    }
};
