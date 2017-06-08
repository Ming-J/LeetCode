#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int first;
      int second;
      for(int i=0;i<nums.size();i++){
	first=i;
	for(int j=0;j<nums.size();j++){
	  second=j;
	  if(target==nums[i]+nums[j]&&i!=j){
	    //cout<<nums[i]<<" "<<nums[j]<<" "<<target<<endl;
	    vector<int> ans;
	    ans.push_back(first);
	    ans.push_back(second);
	    return ans;
	  }
	}
      }
    }
};

int main(){
  Solution test;
  vector<int> nu;
  vector<int> an;
  nu.push_back(3);
  nu.push_back(2);
  nu.push_back(4);
  an=test.twoSum(nu,6);
  for(int i=0;i<an.size();i++){
    cout<<an[i]<<endl;
  }
  cout<<"hello World 10/12"<<endl;
}
