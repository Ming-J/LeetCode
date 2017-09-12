#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      k=k%nums.size();
      int index=k;
      int temp=nums[k];
      do{
	if(index==k){
	  nums[index]=nums[0];
	}else{
	  int store=nums[index];
	  nums[index]=temp;
	  temp=store;
	}
	index=(index+k)%nums.size();
      }while(index!=k);
    }
};
