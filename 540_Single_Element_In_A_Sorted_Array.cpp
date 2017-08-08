#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int singleNonDuplicate(vector<int>& nums){
    if(nums.size()==1){
      return nums[0];
    }
    for(int i=0;i<nums.size();i+=2){
      if(nums[i]!=nums[i+1]){
	return nums[i];
      }
    }
    return nums[nums.size()-1];
  }
};

int main(){
  int arr[9]={1,1,2,3,3,4,4,8,8};
  int arr1[7]={3,3,7,7,10,11,11};
  vector<int> input(arr,arr+sizeof arr/sizeof arr[0]);
  vector<int> input1(arr1,arr1+sizeof arr1/sizeof arr1[0]);
  Solution demo;
  cout<<demo.singleNonDuplicate(input)<<endl;
  cout<<demo.singleNonDuplicate(input1)<<endl;
 
}
