#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool checkPossibility(vector<int>& nums){
    if(nums.size()==1||nums.size()==0){
      return true;
    }
    int pre=0;
    int pos=0;
    for(int i=1;i<nums.size()-1;i++){
      if(nums[i]>nums[i+1]){
	pre++;
	pos=i;
      }
    }
    if(pre>1){return false;}
    if(pre==0){return true;}
    if(pre==1){
      if(pos==0){
	return true;
      }
      if(nums[pos+1]-nums[pos-1]>=0){
	return true;
      }else{return false;}
    }
  }
};
