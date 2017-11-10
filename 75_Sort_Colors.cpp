#include <iostream>
#include <vector>
using namespace std
/*
Given an array with n objects colored red, white or blue, sort them so
that objects of the same color are adjacent, with the colors in the
order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red,
white, and blue respectively.

Note: You are not suppose to use the library's sort function for this
problem.

one pass algorithm to sort the color.
*/
void swap(vector<int>& nums, int ai, int bi){
  int temp=nums[ai];
  nums[ai]=nums[bi];
  nums[bi]=temp;
}

class Solution{
public:
  void sortColors(vector<int>& nums){
    int leftB=0;
    int i=0;
    int rightB=nums.size()-1;
    while(i<=rightB){
      if(nums[i]==0){
	swap(nums,i,leftB);
	i++;
	leftB++;
      }else if(nums[i]==1){
	i++;
      }else{
	swap(nums,i,rightB);
	rightB--;
      }
    }
  }
};
