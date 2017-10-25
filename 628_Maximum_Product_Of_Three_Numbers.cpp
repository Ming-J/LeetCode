#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int maximumProduct(vector<int>& nums){
    sort(nums.begin(),nums.end());
    int neg1=nums[0]*nums[1];
    int pos1=nums[nums.size()-1];
    int pos2=nums[nums.size()-2];
    int pos3=nums[nums.size()-3];
    int tot=pos1*pos2*pos3;
    if(pos1<0&&pos2<0&&pos3<0){
      return tot;
    }
    if(neg1>pos1*pos2||neg1>pos2*pos3){
      return neg1*pos1;
    }else{
      return tot;
    }       
  }
};
