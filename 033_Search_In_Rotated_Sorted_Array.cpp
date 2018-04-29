#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int>& nums,int target){
    if(nums.empty()) return 0;
    if(nums.size() == 1) return (nums[0] == target)? 0 : -1;
    //Binary Search to find the smallest value
    int lo = 0;
    int hi = nums.size() - 1;
    while(lo < hi){
      int mid = lo + (hi - lo)/2;
      if(nums[mid] < nums[hi]){
	hi = mid;
      }else{
	lo = mid + 1;
      }
    }
    int rot = lo;
    //Determining the seection the target is in.
    if( target >= nums[0] && target <= nums[rot-1]){
      lo = 0;
      hi = rot - 1;
    }else{
      lo = rot;
      hi = nums.size() - 1;
    }
    //Preform the binary search in the selected section 
    while(lo <= hi){
      int mid = lo + (hi-lo)/2;
      if(nums[mid] == target){
	return mid;
      }
      if(nums[mid] > target){
	hi = mid-11;
      }else{
	lo = mid+1;
      }
    }
    return -1;
  }
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
