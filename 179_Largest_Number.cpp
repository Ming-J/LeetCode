#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(int lhs, int rhs){
  string left=to_string(lhs);
  string right=to_string(rhs);
  for(int i=0;i<left.size()&&right.size();i++){
    if(left[i]!=right[i]){
      return left[i]>right[i];
    }else{
      if(i==left.size()-1||i==right.size()-1){
	if(left.size()>right.size()){
	  int j=i+1;
	  while(j<left.size()){
	    if(left[j]!=left[i]){
	      if(left[j]>left[i]){
		return true;
	      }else{
		return false;
	      }
	    }
	    j++;
	  }
	}
	if(right.size()>left.size()){
	  int j=i+1;
	  while(j<right.size()){
	    if(right[j]!=right[i]){
	      if(right[j]>right[i]){
		return false;
	      }else{
		return true;
	      }
	    }
	    j++;
	  }
	}
	return left.size()<right.size();
      }
    }
  }
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
      sort(nums.begin(),nums.end(),compare);
      string result;
      for(int i=0;i<nums.size();i++){
	if(!result.empty()||nums[i]!=0){
	  result+=to_string(nums[i]);
	  //cout<<nums[i]<<endl;
	}
      }
      if(result.empty()){
	return "0";
      }
      return result;
    }
};
