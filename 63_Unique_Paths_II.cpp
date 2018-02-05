#include <iostream>
#include <vector>
using namespace std;
/*
  Dynamic Programming
  [1][1][1]
  [1][2][3]
  [1][3][6]
*/
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1 ||
       obstacleGrid[0][0] == 1){
      return 0;
    }
    vector< vector<int> > grid ( obstacleGrid.size() ,
				 vector<int> ( obstacleGrid[0].size() , 0 ) ); 
    for( int i = 0; i < grid.size(); i++){
      for( int j = 0; j < grid[i].size(); j++){
	if( obstacleGrid[i][j] == 1){
	  grid[i][j] == 0;
	}else{
	  if( i == 0 && j == 0 ){
	    grid[i][j] = 1;
	  }else if( i == 0 ){
	    grid[i][j] = grid[i][j-1];
	  }else if( j == 0 ){
	    grid[i][j] = grid[i-1][j];
	  }else{
	    grid[i][j] = grid[i][j-1] + grid[i-1][j];
	  }
	}
      }
    }
    return gridd[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
  }
  int uniquePaths(int m, int n) {
    vector< vector<int> > grid ( m , vector<int> ( n , 0 ) ); 
    for( int i = 0; i < grid.size(); i++){
      for( int j = 0; j < grid[i].size(); j++){
	if( i == 0 && j == 0 ){
	  grid[i][j] = 1;
	}else if( i == 0 ){
	  grid[i][j] = grid[i][j-1];
	}else if( j == 0 ){
	  grid[i][j] = grid[i-1][j];
	}else{
	  grid[i][j] = grid[i][j-1] + grid[i-1][j];
	}
      }
    }
    return grid[m-1][n-1];
  }
};
