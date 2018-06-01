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
    if(nums.size() < 2 || t < 0 || k <= 0) return false;
    set<long long> treeSet;
    for(size_t i = 0; i < nums.size(); ++i){
      //Lower_bound: Return an iterator to the first element not less than the given key
      //Upper_bound: Return an iterator to the first element greater than the given key
      auto lo = treeSet.lower_bound(static_cast<long long>(nums[i]) -
				    static_cast<long long>(t));
      //xauto hi = treeSet.upper_bound(nums[i]);
      if( lo != treeSet.end() &&
	  *lo <= static_cast<long long>(nums[i]) +static_cast<long long> (t)){
	return true;
      }else{
	treeSet.insert(nums[i]);
	if(treeSet.size()>k) treeSet.erase(nums[i-k]);
      }
    }
    return false;
  }
};
