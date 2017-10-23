#include <iostream>
#include <vector>
using namespace std;
/* When doing the binary search to find the lower bound and upper
   bound we can continue to use the search to search [mid+1,.....,end]
   or [start,.....,mid-1]. By using the two binary search, we can have
   a worst time complexity of O(long n)*/
class Solution{
public:
  vector<int> searchRange(vector<int>& nums,int target){
    vector<int> ans;
    if(nums.size()==0){
      ans.assign(2,-1);
      return ans;
    }
    int lo=0;
    int hi=nums.size()-1;
    while(lo<=hi){
      int mid=lo+(hi-lo)/2;
      if(nums[mid]==target){
	return checkRange(nums,mid);
      }
      if(nums[mid]>target){
	hi=mid-1;
      }
      if(nums[mid]<target){
	lo=mid+1;
      }
    }
    ans.assign(2,-1);
    return ans;
  }

  vector<int> checkRange(vector<int>& nums, int index){
    int i1=index;
    int i2=index;
    while(nums[i1]==nums[index]&&i1>=0){
      i1--;
    }
    while(nums[i2]==nums[index]&&i2<nums.size()){
      i2++;
    }
    vector<int> temp;
    temp.push_back(i1+1);
    temp.push_back(i2-1);
    return temp;
  }
};

