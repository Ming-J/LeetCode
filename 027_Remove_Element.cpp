/*
Given an array and a value, remove all instances of that value in
place and return the new length.

Do not allocate extra space for another array, you must do this in
place with constant memory.

The order of elements can be changed. It doesn't matter what you leave
beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of
nums being 2.


Use 2 pointers, one fast running and another slow running. When
iterate the val to remove, we will increase the fast runner. Copy over
the value to replace the slow runner point
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int removeElement(vector<int>& nums, int val){
    int iTwo=0;
    for(int i=0;i<nums.size();i++){
      if(nums[i]!=val){
	nums[iTwo]=nums[i];
	iTwo++;
      }
    }
    return iTwo;
  }
};
