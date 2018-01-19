#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    if(nums.size() == 1){
      return 0;
    }
    
    for(int i=0;i<nums.size();i++){
      int pre;
      if(i-1 == -1){
	pre = INT_MIN;
      }else{
	pre = nums[i-1];
      }
      
      int aft;
      if(i+1 == nums.size()){
	aft = INT_MIN;
      }else{
	aft = nums[i+1];
      }
      
      if(nums[i] > pre && nums[i] > aft){
	return i;
      }
      
    }
    return -1;
    }
};
