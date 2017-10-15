#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <cmath>
using namespace std;
/*
Given a non-empty array of non-negative integers nums, the degree of
this array is defined as the maximum frequency of any one of its
elements.

Your task is to find the smallest possible length of a (contiguous)
subarray of nums, that has the same degree as nums.
*/
class Solution{
public:
  int findShortestSubArray(vector<int>& nums){
    unordered_map<int,int> degree;
    unordered_map<int,int> firstOrc;
    unordered_map<int,int> lastOrc;
    int frequent=0;
    unordered_map<int,int>::iterator it;
    for(int i=0;i<nums.size();i++){
      it=degree.find(nums[i]);
      if(it==degree.end()){
	degree[nums[i]]=0;
	lastOrc[nums[i]]=firstOrc[nums[i]]=i;
      }else{
	degree[nums[i]]++;
	frequent=max(frequent,degree[nums[i]]);
	lastOrc[nums[i]]=i;
      }
    }
    int dif=INT_MAX;
    for(it=degree.begin();it!=degree.end();it++){
      if(it->second==frequent){
	dif=min(dif,lastOrc[it->first]-firstOrc[it->first]+1);
      }
    }
    return dif;
  }
};
