#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int maxAreaOfIsland(vector< vector<int> >& grid){
    int maxA = 0;
    for(size_t i = 0; i < grid.size(); ++i){
      for(size_t j = 0; j < grid[i].size(); ++j){
	if(grid[i][j] == 1){
	  int curA = 0;
	  helperDFS(grid,maxA,curA,j,i);
	}
      }
    }
    return maxA;
  }

  void helperDFS(vector<vector<int> >& grid,int &maxA,int &curA, int c, int r){
    if( r < 0 || r >= grid.size() || c < 0 || c >=grid[0].size()){
      return;
    }
    if(grid[r][c] == 0){
      return;
    }
    grid[r][c] = 0;
    curA++;
    maxA = max(maxA,curA);
    helperDFS(grid,maxA,curA,c+1,r);
    helperDFS(grid,maxA,curA,c-1,r);
    helperDFS(grid,maxA,curA,c,r+1);
    helperDFS(grid,maxA,curA,c,r-1);
  }
};
