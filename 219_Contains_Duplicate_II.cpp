#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k){
    unordered_map<int,int> hash;
    for(int i=0;i<nums.size();i++){
      if(hash.bucket(nums[i])){
	  hash[nums[i]]=i;
	}else{
	  int dif=abs(hash[nums[i]]-i);
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
