#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int minIndex=-1;
      int min=INT_MAX;
      int targetIndex=-1;
      for(int i=0;i<nums.size();i++){
	if(nums[i]<min){
	  min=nums[i];
	  minIndex=i;
	}
	if(target==nums[i]){
	  minIndex=i;
	}
      }
      if(minIndex==-1){
	return -1;
      }else{
	if(minIndex==targetIndex){
	  return 0;
	}else if(minIndex<targetIndex){
	  return targetIndex-minIndex;
	}else{
	  return nums.size()-(minIndex-targetIndex);
	}
      }
    }
};


int main(){
  cout<<"Hello World"<<endl;
}
