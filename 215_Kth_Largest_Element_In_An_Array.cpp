#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int findKthLargest(vector<int>& nums, int k){
    cout<<k<<endl;
    return 0;
  }

  void buildheap(vector<int>& nums){
    
  }

  void heapify(vector<int>& nums, int i){
    int left=left(nums,i);
    int right=right(nums,i);
    int largestIndex=0;
    if(left<=nums.size()&&nums[left]>nums[i]){
      largestIndex=left;
    }else{
      largestIndex=i;
    }
    if(right<=nums.size()&&nums[right]>nums[i]){
      largestIndex=right;
    }
    if(largest!=i){
      
    }
  }

  int parent(vector<int>& nums, int i){
    if(i==0){
      return NULL;
    }else{
      return (i-1)/2;
    }
  }

  int left(vector<int>& nums, int i){
    if(2*i+1<=nums.size()){
      return 2*1+1;
    }else{
      return NULL;
    }
  }

  int right(vector<int>& nums, int i){
    if(2*i+2<=nums.size()){
      return 2*1+2;
    }else{
      return NULL;
    }
  }
};

int main(){
  int arr[6]={3,2,1,5,6,4};
  vector<int> input(arr,arr+sizeof arr/ sizeof arr[0]);
  Solution test;
  test.findKthLargest(input,2);
  cout<<"hello wrold"<<endl;
}
