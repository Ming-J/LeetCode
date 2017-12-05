#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int findUnsortedSubarray(vector<int>& nums){
    vector<int> temp=nums;
    sort(nums.begin(),nums.end());
    int i=0;
    int j=nums.size()-1;
    while(temp[i]==nums[i]&&i<nums.size()){
      i++;
    }
    while(temp[j]==nums[j]&&j>=0){
      j--;
    }
    if(i==nums.size()){
      return 0;
    }else{
      return j-i+1;
    }
  }
};
