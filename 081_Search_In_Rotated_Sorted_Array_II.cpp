#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool search(vector<int>& nums, int target) {
   if(nums.empty()) return false;
    if(nums.size() == 1) return (nums[0] == target)? true : false;
    int lo = 0;
    int hi = nums.size() - 1;
    while(lo < hi){
      int mid = lo + (hi - lo)/2;
      if(nums[mid] == target) return true;
      if(nums[mid] == nums[hi]){
	++lo;
      }else if(nums[mid] <= nums[hi]){
	if(nums[mid] < target && target <= nums[hi]) lo = mid + 1;
	else hi = mid - 1;
      }else{
	if(nums[lo] <= target && target < nums[mid]) hi = mid - 1;
	else lo = mid + 1;
      }
    }
    return false;  
  }
};
