#include <iostream>
#include <vector>
using namespace std;

//use back tracking?

class Solution{
public:
  vector<vector<int>> threeSum(vector<int>& nums){
    vector< vector<int> > result;
    vector<int> tri;
    threeHelper(result,nums,tri,0,0);
    return result;
  }
  void threeHelper(vector< vector<int> > &result,vector<int> &nums, vector<int> tri, int total,int ind){
    if(tri.size()==3){
      if(total==0){
	result.push_back(tri);
      }
      return;
    }else{
      for(int i=ind;i<nums.size();i++){
	tri.push_back(nums[i]);
	threeHelper(result,nums,tri,total+nums[i],i+1);
	tri.pop_back();
      }
    }
  }  
};
