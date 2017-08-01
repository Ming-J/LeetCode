/**************************************************************
Given a sorted array and a target value, return the index if the
target is found. If not, return the index where it would be if it were
inserted in order.

You may assume no duplicates in the array.

Here are few examples.  
[1,3,5,6], 5 → 2 
[1,3,5,6], 2 → 1 
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

**************************************************************/
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
  int searchInsert(vector<int>& nums, int target){
    for(int i=0;i<nums.size();i++){
      if(nums[i]==target){
	return i;
      }
      if(nums.size()==1){
	if(target>nums[i]){
	  return i+1;
	}else{
	  return 0;
	}
      }
      if(i==0){
	if(target<nums[i]){
	  return 0;
	}
      }else if(i==nums.size()-1){
	if(nums[i]<target){
	  return i+1;
	}else{
	  return i;
	}
      }else{
	if(nums[i-1]<target&&target<nums[i]){
	  return i;
	}
      }
    }
  }
};

int main(){
  int arr[4]={1,3,5,6};
  vector<int> input(arr, arr+ sizeof arr/sizeof arr[0]);
  for(int i=0;i<input.size();i++){
    cout<<input[i]<<endl;
  }

  Solution test;
  cout<<test.searchInsert(input,5)<<endl;
  cout<<test.searchInsert(input,2)<<endl;
  cout<<test.searchInsert(input,7)<<endl;
  cout<<test.searchInsert(input,0)<<endl;
  
}
