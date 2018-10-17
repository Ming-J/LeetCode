#include <iostream>
#include <vector>
using namespace std;

//  [1,3]  [2]
//  [1,2] [-1,3]

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() == 0){
      return (nums2.size()%2 == 0)?
	(nums2[nums2.size()/2]+nums2[nums2.size()/2-1]*1.0)/2:
	nums2[nums2.size()/2];
    }
    if(nums2.size() == 0){
      return (nums1.size()%2 == 0)?
	(nums1[nums1.size()/2]+nums1[nums1.size()/2-1]*1.0)/2:
	nums1[nums1.size()/2];
    }
    size_t total = (nums1.size() + nums2.size());
    size_t i1 = 0;
    size_t i2 = 0;
    int prev = 0;
    int current = 0;
    for(size_t i = 0; i <= total/2; ++i){
      prev = current;
      if(i1 == nums1.size()){
	current = nums2[i2];
	++i2;
      }else if(i2 == nums2.size()){
	current = nums1[i1];
	++i1;
      }else if(nums1[i1] > nums2[i2]){
	current = nums2[i2];
	++i2;
      }else{
	current = nums1[i1];
	++i1;
      }
    }
    if(total % 2 == 0){
      return (current+prev)*1.0/2;
    }
    return current;
  }
};

int main(){
  vector<int> v1 ={1, 2};
  vector<int> v2 = {3,4};
  Solution test;
  cout<<test.findMedianSortedArrays(v1,v2)<<endl;
}
