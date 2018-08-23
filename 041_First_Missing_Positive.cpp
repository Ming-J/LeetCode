#include <iostream>
using namespace std;

class Solution{
public:
  int firstMissingPositive(vector<int>& nums){
    //use the array as a hash map, moving the number to the correct index
    //As we are using while loop, have to make sure the number we are switch
    //are not the same
    for(size_t i = 0; i < nums.size(); ++i){
      while(nums[i]>0&&nums[i]<=nums.size()&&nums[i]!=nums[nums[i]-1]){
	swap(nums[i],nums[nums[i] - 1]);
      }
    }
    //first index not match the val is the missing positive number
    for(size_t i = 0; i < nums.size(); ++i){
      if(i+1 != nums[i]) return i+1;
    }
    return nums.size() + 1;
  }
};
