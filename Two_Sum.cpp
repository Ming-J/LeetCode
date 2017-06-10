/**
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 **/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      for(int i=0;i<nums.size();i++){
	for(int j=0;j<nums.size();j++){
	  if(target==nums[i]+nums[j]&&i!=j){
	    //cout<<nums[i]<<" "<<nums[j]<<" "<<target<<endl;
	    vector<int> ans;
	    ans.push_back(i);
	    ans.push_back(j);
	    return ans;
	  }
	}
      }
    }
};

int main(){
  Solution test;
  vector<int> nu;
  vector<int> an;
  nu.push_back(3);
  nu.push_back(2);
  nu.push_back(4);
  an=test.twoSum(nu,6);
  for(int i=0;i<an.size();i++){
    cout<<an[i]<<endl;
  }
  cout<<"hello World 10/12"<<endl;
}
