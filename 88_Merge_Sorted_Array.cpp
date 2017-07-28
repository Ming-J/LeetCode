/*********************************************************************

Given two sorted integer arrays nums1 and nums2, merge nums2 into
nums1 as one sorted array.

Note: You may assume that nums1 has enough space (size that is greater
or equal to m + n) to hold additional elements from nums2. The number
of elements initialized in nums1 and nums2 are m and n respectively.

**********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  void merge( vector<int>& nums1, int m, vector<int>& nums2, int n){
    cout<<m<<" "<<n<<endl;
    if(n==0){
      return;
    }
    if(m==0){
      nums1=nums2;
      return;
    }
    int i=m-1;
    int j=n-1;
    int index=nums1.size()-1;
    while(i>=0&&j>=0){
      if(nums2[j]>nums1[i]){
	nums1[index]=nums2[j];
	j--;
      }else{
	nums1[index]=nums1[i];
	i--;
      }
      index--;
    }
    while(j>=0){
      nums1[index--]=nums[j--];x
    }
    return;
  }
};

int main(){
  Solution test;
  int input1[9]={-1,0,0,3,3,3,0,0,0};
  int input2[3]={1,2,2};
  vector<int> v1(input1, input1+9);
  vector<int> v2(input2, input2+3);
  test.merge(v1,6,v2,3);
}
