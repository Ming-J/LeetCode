#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    if(nums.size() == 0) return 0;
    int newVal = 0;
    for(size_t i = 0; i < nums.size(); ++i){
      if(nums[i] != val){
	nums[newVal] = nums[i];
	++newVal;
      }
    }
    return newVal;
  }
};
