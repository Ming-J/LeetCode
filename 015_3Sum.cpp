#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution{
public:
  vector<vector<int>> threeSum(vector<int>& nums){
    vector< vector<int> > result;
    if(nums.size() < 3) return result;
    sort(nums.begin(),nums.end());
    for(size_t i = 0; i < nums.size() - 2; ++i){
      //never let i refer to the same value twice
      if(i != 0 && nums[i] == nums[i-1]) continue;
      int lo = i + 1;
      int hi = nums.size() - 1;
      while(lo < hi){
	cout<<nums[i]<<' '<<nums[lo]<<' '<<nums[hi]<<endl;
	if((nums[i] + nums[lo] + nums[hi]) == 0){
	  result.push_back({nums[i],nums[lo],+nums[hi]});
	  ++lo;
	  while(lo<hi&&nums[lo] == nums[lo-1]) ++lo;
	}else if((nums[i] + nums[lo] + nums[hi]) < 0){
	  ++lo;
	}else{
	  --hi;
	}
      }
    }
    return result;
  }        
};

int main(){
  vector<int> input = {-1,-1,0,1};
  Solution test;
  test.threeSum(input);
}
