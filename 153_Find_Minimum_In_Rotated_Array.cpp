#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    int lo = 0;
    int hi = nums.size() - 1;
    while(lo < hi){
      int mid = lo + (hi - lo)/2;
      //Always comparing to the end
      if(nums[mid] > nums[hi]){
	lo = mid + 1;
      }else{
	hi = mid;
      }
    }
    return lo;
  }
};
