#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*using map to store the count of all numbers, check to see if there
  is adjacent number. Add the count of both number if the adjacent
  number is present.*/
class Solution{
public:
  int findLHS(vector<int>& nums){
    map<int,int> hash;
    for(int i=0;i<nums.size();i++){
      hash[nums[i]]++;
    }
    auto previous=hash.begin();
    int maxlength=0;
    for(auto i=hash.begin();i!=hash.end();i++){
      if(abs(i->first-previous->first)==1){
	maxlength=max(maxlength,i->second+previous->second);
      }
      previous=i;
    }
    return 0;
  }
};
