#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int> > ans;
    vector<int> cur;
    backtracking(ans,cur,nums,0);
    return ans;
  }

private:
  void backtracking(vector<vector<int>>& ans, vector<int>& cur,
		    vector<int>& nums, int begin){
    ans.push_back(cur);
    for(int i = begin; i < nums.size(); ++i){
      cur.push_back(nums[i]);
      backtracking(ans,cur,nums,i+1);
      cur.pop_back();
    }
  }
};


int main(){
  Solution test;
  vector<int> tests={1,2,3};
  for(auto li : test.subsets(tests)){
    for(auto i : li){
      cout<<i<<' ';
    }
    cout<<endl;
  }

}
