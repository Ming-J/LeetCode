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
<<<<<<< HEAD
	}
	cout<<nums[i]<<endl;
=======
	  //cout<<nums[i]<<endl;
	}
      }
      if(result.empty()){
	return "0";
>>>>>>> afefa891aaa361ad99e6fb4a775836f1b9c124b3
      }
      if(result.empty()){
	return "0";
      }
      return result;
    }
};
