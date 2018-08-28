#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
  int jump(vector<int>& nums) {
    if(nums.size() <= 1) return 0;
    int step = 0, start = 0, end = 0;
    while(end < nums.size() - 1){
      ++step;
      int maxEnd = end + 1;
      for(int i = start; i <= end; ++i){
	maxEnd = max(maxEnd,i+nums[i]);
	if(i+nums[i] >= nums.size() - 1) return step;
      }
      start = end + 1;
      end = maxEnd;
    }
    return step;
  }
};
