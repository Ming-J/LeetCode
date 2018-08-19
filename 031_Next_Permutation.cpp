#include <iostream>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int largestIndex = -1;
    for(size_t i = 0; i < nums.size() - 1; ++i){
      if(nums[i] < nums[i+1]) largestIndex = i; 
    }
    if(largestIndex == -1) reverse(nums.begin(),nums.end());
    else{
      int l = -1;
      for(int i = largestIndex; i < nums.size() ; ++i){
	if(nums[i] > nums[largestIndex]) l = i;
      }
      swap(nums[largestIndex],nums[l]);
      reverse(nums.begin()+largestIndex+1,nums.end());
    }  
    return;
  }
};
