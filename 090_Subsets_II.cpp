#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    vector<int> cur;
    backtrack(ans,cur,nums,0);
    return ans;
  }

private:
  void backtrack(vector<vector<int>>& ans, vector<int>& cur,
		 vector<int>& nums, int begin){
    ans.push_back(cur);
    for(int i = begin; i < nums.size(); ++i){
      if(i == begin || nums[i] != nums[i-1]){
	cur.push_back(nums[i]);
	backtrack(ans, cur, nums, i+1);
	cur.pop_back();
      }
    }
  }
};


int main(){
  Solution test;
  vector<int> tests={1,2,2};
  for(auto li : test.subsetsWithDup(tests)){
    for(auto i : li){
      cout<<i<<' ';
    }
    cout<<endl;
  }

}
