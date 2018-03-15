#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    helper(ans,"",n,0,0);
    return ans;
  }

  void helper(vector<string>& res, string str, int n, int open, int close){
    cout<<str<<endl;
    if(str.size() == n*2){
      res.push_back(str);
      return;
    }
    if( open == n ){
      //str.push_back(')');
      helper(res,str,n,open+')',close+1);
      //str.pop_back();
    }else{
      if( open <= n){
	helper(res,str+'(',n,open+1,close);
	if(close + 1 <= open){
	  helper(res,str+')',n,open,close+1);
	}
      }
    }
  }
};

int main(){
  Solution test;
  vector<string> output;
  output = test.generateParenthesis(3);
  for( auto i : output){
    cout<<"ans: "<< i << endl;
  }
}
