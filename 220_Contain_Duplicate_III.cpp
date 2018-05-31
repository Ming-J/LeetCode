#include <iostream>
#include <vector>
#include <set>
using namespace std;
//using a sliding window method and a treeSet dataStructure.
//Maintaining a k size tree set and check for lowerbound and upperbound
//if lowerbound and upperbound are within t then retrun true
class Solution{
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
    if(nums.size() < 2 || t < 0) return false;
    set<int> treeSet;
    for(size_t i = 0; i < nums.size(); ++i){
      auto lo = treeSet.lower_bound(nums[i]);
      auto hi = treeSet.upper_bound(nums[i]);
      if(lo!=treeSet.end() && *lo == nums[i]) return true;
      if(lo==treeSet.begin() && abs(*lo - nums[i])<=t) return true;  
      if((lo!=treeSet.end()&&abs(*(--lo)-nums[i])<=t)||
	 (hi!=treeSet.end()&&abs(*hi-nums[i])<=t)){
	return true;
      }else{
	treeSet.insert(nums[i]);
	if(treeSet.size()>k) treeSet.erase(nums[i-k]);
      }
    }
    return false;
  }
};
