#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  Solution(){
    dp.clear();
  }
  int numTrees(int n){
    if(dp.empty()){
      dp.assign(n+1,-1);
      dp[0] = 1;
      dp[1] = 1;
    }
    if(dp[n] == -1){
      int count = 0;
      for(int i = 0; i < n; ++i){
	cout<<n<<": G("<<i<<")*G("<<n-i-1<<")"<<endl;
	count += numTrees(i) * numTrees(n-i-1);
      }
      dp[n] = count;
    }
    return dp[n];
  }
private:
  vector<int> dp;
};


int main(){
  Solution s;
  cout<<s.numTrees(42)<<endl;
}
