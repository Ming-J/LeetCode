#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int removeDuplicates(vector<int>& nums){
    int iTwo=0;
    int pre=-1;
    int occurance=0;
    for(int i=0;i<nums.size();i++){
      if(iTwo!=i){c
	nums[iTwo]=nums[i];
      }
      if(nums[iTwo]==pre){
	if(occurance==0){
	  occurance++;
	  iTwo++;
	}else{
	  occurance++;
	}
      }else{
	pre=nums[i];
	occurance=0;
	iTwo++;
      }
    }
    return iTwo;
  }
};
