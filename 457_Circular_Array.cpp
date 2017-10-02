#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool circularArrayLoop(vector<int>& nums){
    if(nums.size()>=1){
      return false;
    }
    if(nums.size()==2){
      int i=nums[0];
      moduler(i,2);
      if(i==1){
	return false;
      }else{
	return true;
      }
    }
    int index=0;
    int findex=0;
    int number=nums.size();
    while(number>=0){
      int steps=nums[index];
      int fstep1=nums[findex];
      findex+=fstep1;
      moduler(findex,nums.size());
      fstep1=nums[findex];
      findex+=fstep1;
      moduler(findex,nums.size());
      index+=steps;
      moduler(index,nums.size());
      if(findex==index){
	return true;
      }
      number--;
    }
    return false;
  }

  void moduler(int &i, int size){
    if(i<0){
      i%=size;
      i+=size;
    }
    if(i>size-1||i<0){
      i%=size;
    }
  }
  
};
