#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidate.end());
    vector< vector<int> > result;
    
    return result;
  }
  void helper(vector< vector<int> > &ans, vector<int> &sum, int index,
	      vector<int>& candidates,int curSum,int tarSum){
    if(curSum==tarSum){
      ans.push_back(sum);
    }else{
      for(int i=index;i<candidates.sum();i++){
	
	help(ans,sum,index+1,candidates,curSum+candidates,tarSum);
      }
    }
  }
  
};
