#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    if(nums.size() < 2) return false;
    if(k == 0){
      for(size_t i = 1; i < nums.size(); ++i){
	if(nums[i-1]==0 && nums[i]==0){
	  return true;
	}
      }
    }else{
      unordered_map<int,int> rem;
      int sum = 0;
      for(size_t i = 0; i < nums.size(); ++i){
	sum += nums[i];
	if(rem.find(sum%k)==rem.end()&&sum%k!=0){
	  rem[sum%k]=i;
	}else{
	  if(i - rem[sum%k] >= 1||(i>0 && sum%k == 0)){
	    return true;
	  } 
	}
      }
    }
    return false;
  }
};
