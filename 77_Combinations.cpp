#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<vector<int> > combine(int n, int k){
    vector< vector<int> > ans;
    if(n==0){
      return ans;
    }
    vector<int> set;
    helper(ans, set, n, k,1);
    return ans;
  }

  void helper(vector< vector<int> > &ans,vector<int> row, int n,int k,int st){
    if(row.size()==k){
      ans.push_back(row);
    }else{
      for(size_t i=st;i<=n;i++){
	row.push_back(i);
	helper(ans,row,n,k,i+1);
	row.pop_back();
      }
    }
  }
};
