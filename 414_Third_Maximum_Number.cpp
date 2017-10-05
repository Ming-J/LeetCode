#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Solution{
public:
  int thirdMax(vector<int>& nums){
    if(nums.size()==1){
      return nums[0];
    }
    if(nums.size()==2){
      if(nums[1]>nums[0]){
	return nums[1];
      }else{
	return nums[0];
      }
    }
    long max1=LONG_MIN, max2=LONG_MIN, max3=LONG_MIN;
    for(int i=0;i<nums.size();i++){
      if(nums[i]>max1){
	max3=max2;
	max2=max1;
	max1=nums[i];
      }else if(nums[i]>max2&&nums[i]<max1){
	max3=max2;
	max2=nums[i];
      }else if(nums[i]>max3&&nums[i]<max2){
	max3=nums[i];
      }
    }
    if(max3==LONG_MIN){
      return max1;
    }
    return max3;
  }
};
