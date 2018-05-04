#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  int numDecodings(string s){
    if(s.size() == 0) return 0;
    vector<int> dp(s.size()+1,0);
    dp[0] = 1;
    for(size_t i = 0; i < s.size(); ++i){
      string single = s.substr(i,1);
      if(i == 0){
	dp[i+1] = stoi(single) > 0? 1 : 0;
      }else{
	if(stoi(single) > 0){
	  dp[i+1] += dp[i];
	}
	string twoDigits = s.substr(i-1,2);
	if(stoi(twoDigits) >= 10 && stoi(twoDigits) <= 26){
	  dp[i+1] += dp[i-1];
	}
      }
    }
    return dp[s.size()];
  }
};

int main(){
  string input = "0";
  Solution test;
  cout<<test.numDecodings(input)<<endl;
}
