#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> ans;
    dfs(num,target,ans,"",0,0,0);
    return ans;
  }

private:
  void dfs(const string num, const int target,
	   vector<string>& res, string expr, int n, long prev, long cur){
    if(n==num.size()){
      if(target == cur) res.push_back(expr);
      return;
    }
    for(int l = 1; l <= num.size() - n; ++l){
      string t = num.substr(n,l);
      if(t[0] == '0' && t.length() > 1) break;
      long newVal = stol(t);
      if(newVal > INT_MAX) break;
      if(n == 0){
	dfs(num,target,res,expr+t,n+l,newVal,newVal);
	continue;
      }
      dfs(num,target,res,expr+'+'+t,n+l,newVal,cur+newVal);
      dfs(num,target,res,expr+'-'+t,n+l,-newVal,cur-newVal);
      dfs(num,target,res,expr+'*'+t,n+l,prev * newVal,
	  cur - prev+newVal*prev);
    }
  }
};


