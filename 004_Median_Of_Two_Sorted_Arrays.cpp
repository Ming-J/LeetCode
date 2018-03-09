#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int total=nums1.size()+nums2.size();
    int medianIndex=total/2;
    int i=0;
    int j=0;
    int current=0;
    int p1=0;
    int count=0;
    while(medianIndex>=count){
      p1=current;
      if(i==nums1.size()){
	 current=nums2[j];
	j++;
      }else if(j==nums2.size()){
	current=nums1[i];
	i++;
      }else{
	if(nums1[i]>nums2[j]){
	  current=nums2[j];
	  j++;
	}else{
	  current=nums1[i];
	  i++;
	}
      }
      count++;
    }
    cout<<p1<<" "<<current<<endl;
    if(total%2==0){
      return (current+p1)*1.0/2;
    }else{
      return current;
    }
  }
};

int main(){
  int arr1[3]={1,2,5};
  int arr2[2]={3,4};
  vector<int> input1(arr1,arr1+sizeof arr1/sizeof arr1[0]);
  vector<int> input2(arr2,arr2+sizeof arr2/sizeof arr2[0]);
  Solution test;
  cout<<test.findMedianSortedArrays(input1, input2)<<endl;
}
