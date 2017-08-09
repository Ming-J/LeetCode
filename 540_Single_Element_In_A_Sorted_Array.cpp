
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int singleNonDuplicate(vector<int>& nums){
    int length=nums.size();
    if(length==1){
      return nums[0];
    }
    int low=0;
    int high=nums.size()-1;
    while(high>low){
      int mid=(low+high)/2;
      cout<<"a"<<mid<<endl;
      if(nums[mid]==nums[mid-1]){
	if((mid-2-low+1)%2==0){
	  low=mid+1;
	}else{
	  high=mid-2;
	}
      }else if(nums[mid]==nums[mid+1]){
	if((mid-1-low+1)%2==0){
	  low=mid+2;
	}else{
	  high=mid-1;
	}
      }else{
	return nums[mid];
      }
    }
    return nums[low];
    // for(int i=0;i<nums.size();i+=2){
    //  if(nums[i]!=nums[i+1]){
    //	return nums[i];
    //  }
    //}
    //return nums[nums.size()-1];
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
