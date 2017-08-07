/*
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int findKthLargest(vector<int>& nums, int k){
    heapsort(nums);
    return nums[k-1];
  }

  void heapsort(vector<int>& nums){
    buildheap(nums);
    for(int i=nums.size()-1;i>=0;i--){
      int tmp=nums[i];
      nums[i]=nums[0];
      nums[0]=tmp;
      heapify(nums,i,0);
    }
  }
  
  void buildheap(vector<int>& nums){
    for(int i=(nums.size()-2)/2;i>=0;i--){
      //cout<<i<<endl;
      heapify(nums,nums.size(),i);
    }
  }

  void heapify(vector<int>& nums,int size, int i){
    //cout<<i<<endl;
    if(i<0){return;}
    int le=left(i);
    int ri=right(i);
    int largestIndex=0;
    if(le<size&&nums[le]>nums[i]){
      largestIndex=le;
    }else{
      largestIndex=i;
    }
    if(ri<size&&nums[ri]>nums[largestIndex]){
      largestIndex=ri;
    }
    if(largestIndex!=i){
      int temp=nums[largestIndex];
      nums[largestIndex]=nums[i];
      nums[i]=temp;
      heapify(nums,size,largestIndex);
    }
  }

  int parent(vector<int>& nums, int i){
    if(i%2==0){
      return i/2-1;
    }else{
      return i/2;
    }
  }

  int left(int i){
      return 2*i+1;
  }

  int right(int i){
      return 2*i+2;
  }
};

int main(){
  int arr[6]={3,2,1,5,6,4};
  vector<int> input(arr,arr+sizeof arr/ sizeof arr[0]);
  Solution test;
  test.findKthLargest(input,2);
  cout<<"hello wrold"<<endl;
}
