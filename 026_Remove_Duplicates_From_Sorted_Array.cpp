#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int removeDuplicates(vector<int>& nums){
    int size=nums.size();
    if(size==0||size==1){
      return size;
    }
    int index=0;
    for(int i=1;i<nums.size();i++){
      if(nums[index]==nums[i]){
	size--;
      }else{
	index++;
	nums[index]=nums[i];
      }
    }
    return size;
  }
};

int main(){
  int arr[3]={1,1,1};
  vector<int> input(arr, arr+sizeof arr/sizeof arr[0]);
  Solution test;
  test.removeDuplicates(input);
}
