#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums){
    unordered_map<int,int> hash;
    for(int i=0;i<nums1.size();i++){
      hash[nums1[i]]++;
    }
    vector<int> result;
    for(int i=0;i<nums.size();i++){
      if(hash[nums[i]]){
	hash[nums[i]]--;
	result.push_back(nums[i]);
      }
    }
    return result;
  }
};
