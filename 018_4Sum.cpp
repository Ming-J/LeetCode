/*
1, 0, -1, 0, -2, 2

1,0,-1,0  1,0,-1,-2  1,0,-1,2
0,-1,0,-2  0,-1,0,2


 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector< vector<int> >fourSum(vector<int>& nums, int target){
    vector< vector<int> > ans;
    if(nums.size() < 4) return ans;
    sort(nums.begin(),nums.end());
    for(size_t i = 0; i < nums.size()-3; ++i){
      for(size_t j = i+1; j < nums.size() - 2; ++j){
	size_t lo = j + 1;
	size_t hi = nums.size() - 1;
	while(lo < hi){
	  int sum = nums[i] + nums[j] + nums[lo] + nums[hi];
	  if(sum < target){
	    ++lo;
	  }else if(sum > target){
	    --hi;
	  }else{
	    ans.push_back({nums[i],nums[j],nums[lo],nums[hi]});
	    ++lo;
	    --hi;
	  }
	}
      }
    }
    sort(ans.begin(),ans.end());
    //unique - remove consecutive duplicate in range return new size
    //erase - 
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    return ans;
  }
};

int main(){
  int arr[6]={4,3,-1,2,-2,10};
  vector<int> input(arr,sizeof arr/arr[0]+arr);
  Solution test;
  test.fourSum(input,0);
  cout<<"Hello World"<<endl;
}
