#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
  vector<int> intersection(vector<int> nums1, vector<int>& nums2){
    unordered_map<int> hash;
    for(int i=0;i<nums1.size();i++){
      hash.insert(nums[i]);
    }
    for(int i=0;i<nums2.size();i++){
      hash
    }
  }
};

int main(){
  Solution test;
  int arr1[4]={1,2,2,1};
  int arr2[5]={2,2};
  vector<int> input1(arr1,arr1+sizeof arr1/sizeof arr1[0]);
  vector<int> input2(arr2,arr2+sizeof arr2/sizeof arr2[0]);
  vector<int> output=test.intersection(input1,input2);
}
