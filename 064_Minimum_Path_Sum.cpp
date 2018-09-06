#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    if(grid.empty() || grid[0].empty()) return 0;
    vector< vector<int> > dp(grid.size(),vector<int>(grid[0].size(),0));
    dp[0][0] = grid[0][0];
    for(size_t i = 1; i < grid.size(); ++i){
      dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for(size_t j = 1; j < grid[0].size(); ++j){
      dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    for(size_t i = 1; i < grid.size(); ++i){
      for(size_t j = 1; j < grid[i].size(); ++j){
	dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
      }
    }
    return dp[grid.size()-1][grid[0].size()-1];
  }
};

int main(){
  Solution test;
  vector<vector<int> > input = {{1,7,4,3,2,2,2,9,2,6},{3,6,6,1,0,5,9,6,3,8},{1,5,4,5,3,8,7,2,5,6},{5,7,6,9,0,8,1,4,7,5},{0,2,1,9,5,3,6,5,9,9},{5,3,6,1,8,9,0,7,4,7},{6,9,4,2,0,6,0,3,2,9},{8,3,3,1,2,9,5,8,6,6},{9,1,9,5,4,7,6,4,5,0},{4,1,1,8,5,1,7,5,4,9},{6,4,4,9,8,8,8,5,8,4},{1,7,7,3,2,4,0,9,8,7},{1,4,0,3,5,5,4,2,2,1},{3,0,5,8,0,3,6,0,0,5},{7,2,4,6,5,7,0,7,8,1},{7,9,5,7,4,0,5,1,4,9},{2,8,0,9,8,2,5,6,2,5},{3,9,9,8,6,4,7,8,4,5},{9,1,6,5,0,3,5,5,4,0}};
  cout<<test.minPathSum(input)<<endl;
}
