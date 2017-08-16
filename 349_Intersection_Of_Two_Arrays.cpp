#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  vector<int> intersection(vector<int> nums1, vector<int>& nums2){
    unordered_map<int,int> hash;
    vector<int> out;
    for(int i=0;i<nums1.size();i++){
      hash[nums1[i]]=0;
    }
    for(int i=0;i<nums2.size();i++){
      unordered_map<int,int>:: iterator it;
      it=hash.find(nums2[i]);
      if(it!=hash.end()){
	if(it->second==0){
	  out.push_back(nums2[i]);
	  hash[nums2[i]]=1;
	}
      }
    }
    // for(int i=0;i<out.size();i++){
    //  cout<<out[i]<<endl;
    //}
    return out;
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
