#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    vector<vector<int> > dp(dungeon.size(),vector<int> (dungeon[0].size(),0));
    for( size_t i = dungeon.size() -1; i < dungeon.size(); --i){
      for( size_t j = dungeon[i].size() - 1; j < dungeon[i].size(); --j){
	if(i == dungeon.size() - 1 && j == dungeon[i].size() - 1){
	  //initialing 
	  dp[i][j] = max(1, 1 - dungeon[i][j]);
	}else if(i == dungeon.size() - 1){
	  //last row
	  dp[i][j] = max(1, dp[i][j+1] - dungeon[i][j]);
	}else if(j == dungeon[i].size() - 1){
	  //last column
	  dp[i][j] = max(1, dp[i+1][j] - dungeon[i][j]);
	}else{
	  dp[i][j] = max(1, min(dp[i][j+1],dp[i+1][j]) - dungeon[i][j]);
	}
      }
    }

    for( auto i : dp){
      for( auto j : i){
	cout<<j<<' ';
      }
      cout<<endl;
    }
    return 0;
  }
};

int main(){
  Solution test;
  test.calculateMinmumHP
}
