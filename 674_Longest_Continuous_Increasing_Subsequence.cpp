#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int findLengthOfLCIS(vector<int>& nums){
    if(nums.size()==0){
      return 0;
    }
    if(nums.size()==1){
      return 1;
    }
    int count=1;
    int max1=0;
    for(int i=1;i<nums.size();i++){
      if(nums[i]>nums[i-1]){
	count++;
      }else{
	max1=max(count,max);
	count++;
      }
    }
    return max;
  }
};
