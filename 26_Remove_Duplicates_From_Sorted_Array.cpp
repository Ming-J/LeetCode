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
    int current=nums[0];
    int count=0;
    for(int i=1;i<nums.size();i++){
      if(current==nums[i]){
	size--;
      }else{
	current=nums[i];
	count++;
      }
      nums[count]=nums[i];
    }
    for(int i=0;i<size;i++){
      cout<<nums[i]<<endl;
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
