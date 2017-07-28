#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  void moveZeroes(vector<int>& nums) {
    int index=0;
    for(int i=0;i<nums.size();i++){
      while(i+index<nums.size()&&nums[i+index]==0){
	  index++;
      }
      if(index!=0){
	if(i+index<nums.size()){
	    nums[i]=nums[i+index];
	}else{
	  nums[i]=0;
	}
      }
    }
    for(int i=0;i<nums.size();i++){
      cout<<nums[i]<<endl;
    }
  }
};

int main(){
  int nums[5]={0,1,0,3,12};
  vector<int> input(nums,nums+sizeof nums / sizeof nums[0]);
  Solution test;
  test.moveZeroes(input);
}
