#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int> >& grid) {
      if(grid.size()==0||grid[0].size()==0){
	return 0;
      }
      //vector<bool> vr(grid[0].size(),false);
      vector< vector<bool> > visited(grid.size(),
				     vector<bool>(grid[0].size(),false));
      int primeter=0;
      for(size_t i=0;i<grid.size();i++){
	for(size_t j=0;grid[j].size();j++){
	  if(grid[i][j]){
	    dsf(grid,primeter,i,j,visited);
	  }
	}
      }
      return primeter;
    }

  void dsf(vector<vector<int> >& grid, int &primeter, int row, int col,
	   vector<vector<bool> > &visited){
    int rowUB=grid.size();
    int colUB=grid[0].size();
    if(row>=0&&row<rowUB&&col>=0&&col<colUB){
      if(visited[row][col]){
	return;
      }
      visited[row][col]=true;
      if(grid[row][col]==0){
	return;
      }
      if(row==0){primeter++;}
      if(col==0){primeter++;}
      if(row==grid.size()-1){primeter++;}
      if(col==grid[row].size()-1){primeter++;}
      if(grid[row+1][col]==0){primeter++;}
      if(grid[row-1][col]==0){primeter++;}
      if(grid[row][col+1]==0){primeter++;}
      if(grid[row][col-1]==0){primeter++;}
      dsf(grid,primeter,row+1,col,visited);
      dsf(grid,primeter,row-1,col,visited);
      dsf(grid,primeter,row,col+1,visited);
      dsf(grid,primeter,row,col-1,visited);
    }
  }
};
