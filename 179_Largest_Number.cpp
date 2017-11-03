#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(int lhs, int rhs){
  string left=to_string(lhs);
  string right=to_string(rhs);
  return (left+right)>(right+left);
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
      sort(nums.begin(),nums.end(),compare);  //sorting weill be nlogn, compare each string will be k(average of the string)
      string result="";
      for(int i=0;i<nums.size();i++){
	if(!result.empty()||nums[i]!=0){
	  result+=to_string(nums[i]);
	}
	cout<<nums[i]<<endl;
      }
      if(result.empty()){
	return "0";
      }
      return result;
    }
};
