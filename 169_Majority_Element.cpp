#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int majorityElement(vector<int>& nums){
    int max=0;
    unordered_map<int,int>::iterator c;
    unordered_map<int,int> hash;
    for(int i=0;i<nums.size();i++){
      unordered_map<int,int>::iterator it=hash.find(nums[i]);
      if(it==hash.end()){
	hash[nums[i]]=1;
      }else{
	hash[nums[i]]++;
      }
    }
    for(unordered_map<int,int>::iterator i=hash.begin();i!=hash.end();i++){
      if(i->second>max){
	max=i->second;
	c=i;
      }
    }
    return c->first;
  }
};
