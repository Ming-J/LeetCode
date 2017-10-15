#include <iostream>
#include <vector>
using namespace std;
/*Given an array of n integers where n > 1, nums, return an array
  output such that output[i] is equal to the product of all the
  elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up: Could you solve it with constant space complexity? (Note:
The output array does not count as extra space for the purpose of
space complexity analysis.)
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> front(nums.size(),0);
      vector<int> back(nums.size(),0);
      vector<int> ans(nums.size(),0);
      int pre=1;
      for(size_t i=0;i<nums.size();i++){
	front[i]=pre;
	pre*=nums[i];
      }
      pre=1;
      for(size_t i=nums.size();i-->0;){
	back[i]=pre;
	pre*=nums[i];
      }
      for(size_t i=0;i<nums.size();i++){
	ans[i]=back[i]*front[i];
      }
      return ans;
    }
};
