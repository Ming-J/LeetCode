#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> findErrorNums(vector<int>& nums){
    vector<int> result;
    for(int i=0;i<nums.size();i++){
      int index=abs(nums[i])-1;
      if(nums[index]>0){
	nums[index]*=-1;
      }else{
	result.push_back(index+1);
      }
    }
    for(int i=0;i<nums.size();i++){
      if(nums[i]>0){
	result.push_back(i+1);
      }
    }
    return result;
  }
};
