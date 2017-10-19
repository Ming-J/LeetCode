#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<string> summaryRanges(vector<int>& nums){
    vector<string> rtn;
    if(nums.size()==0){
      rtn.push_back("");
      return rtn; 
    }
    if(nums.size()==1){
      rtn.push_back(to_string(nums[0]));
      return rtn; 
    }
    int count=1;
    int pre=nums[0];
    string head=to_string(nums[0]);
    for(int i=1;i<nums.size();i++){
      if(pre+1==nums[i]){
	count++;
      }else{
	if(count==1){
	  rtn.push_back(head);
	}else{
	  rtn.push_back(head+"->"+to_string(nums[i-1]));
	}
	count=1;
	head=to_string(nums[i]);
      }
      pre=nums[i];
    }
    if(count==1){
      rtn.push_back(head);
    }else{
      rtn.push_back(head+"->"+to_string(nums[nums.size()-1]));
    }
    return rtn;
  }
};

int main(){
  int arr[7]={0,2,3,4,6,8,9};
  vector<int> inp(arr,arr+sizeof arr/sizeof arr[0]);
  Solution test;
  vector<string> result=test.summaryRanges(inp);
  for(int i=0;i<result.size();i++){
    cout<<result[i]<<endl;
  }
}
