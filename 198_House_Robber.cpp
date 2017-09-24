#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    //Edge Case
    if(nums.size()==0){return 0;}
    vector<int> stash;
    //Creating DP array with 2 Base Case
    for(int i=0;i<nums.size();i++){
      if(i==0){
	stash.push_back(nums[i]);
      }else if(i==1){
	stash.push_back(max(nums[1],nums[0]));
      }else{
	stash.push_back(max(stash[i-1],stash[i-2]+nums[i]));
      }
    }
    return stash[nums.size()-1];
  }
};


int main(){
  cout<<"Hello World"<<endl;
}
