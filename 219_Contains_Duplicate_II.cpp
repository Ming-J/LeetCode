#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k){
    unordered_map<int,int> hash;
    for(int i=0;i<nums.size();i++){
      if(hash.count(nums[i])==0){
	  hash[nums[i]]=i+1;
	}else{
	int dif=abs(hash[nums[i]]-(i+1));
	  if(k>=dif){
	    return true;
	  }
	}
    }
    return false;
  }
};

int main(){
  return 0;
}
