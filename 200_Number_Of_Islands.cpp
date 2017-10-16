#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      if(grid.size()==0){
	return 0;
      }
      int numberOfIsland=0;
      vector< vector<bool> > truth(grid.size(),
				   vector<bool> (grid[0].size(),false));
      for(size_t i=0;i<grid.size();i++){
	for(size_t j=0;j<grid[i].size();j++){
	  if(grid[i][j]=='1'&&truth[i][j]==false){
	    numberOfIsland++;
	    helper(grid,truth,i,j);
	  }
	}
      }
      return numberOfIsland;
    }
  void helper(vector<vector<char> >& grid, vector<vector<bool>> &tru, int row, int col){
    if(row<0||row>=grid.size()||col<0||col>=gird[0].size()){
      return;
    }
    if(tru[row][col]==true){
      return;
    }else{
      if(row>=0&&row<grid.size()&&col>=0&&col<grid[row].size()){
	//print(tru);
	if(grid[row][col]=='1'){
	  tru[row][col]=true;
	  helper(grid,tru,row+1,col);
	  helper(grid,tru,row-1,col);
	  helper(grid,tru,row,col+1);
	  helper(grid,tru,row,col-1);
	}else{
	  return;
	}
      }
    }
  }


  void print(vector<vector<bool>> tru){
    for(int i=0;i<tru.size();i++){
      for(int j=0;j<tru[i].size();j++){
	if(tru[i][j]==true){
	  cout<<'T';
	}else{
	  cout<<'F';
	}
      }
      cout<<endl;
    }
  }
};
