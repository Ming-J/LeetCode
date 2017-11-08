#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
public:
  int maxSubArray(vector<int>& nums){
    int max_end_here=nums[0],max_so_far=nums[0];
    for(int i=1;i<nums.size();i++){
      max_end_here=max(nums[i],max_end_here+nums[i]);
      max_so_far=max(max_so_far,max_end_here);
    }
    return max_so_far;
  }
};

