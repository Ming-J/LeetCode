#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector< vector<int> > result;
    vector<int> sum;
    helper(result,sum,0,candidates,0,target);
    return result;
  }
  void helper(vector< vector<int> > &ans, vector<int> &sum, int index,
	      vector<int>& candidates,int curSum,int tarSum){
    if(curSum==tarSum){
      ans.push_back(sum);
    }else{
      for(int i=index;i<candidates.size();i++){
	sum.push_back(candidates[i]);
	helper(ans,sum,index+1,candidates,curSum+candidates[i],tarSum);
	sum.pop_back();
      }
    }
  }
  
};
