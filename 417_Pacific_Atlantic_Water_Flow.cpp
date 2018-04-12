#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    m = matrix;
    vector<pair<int,int> > ans;
    vector< vector<bool> > visit(m.size(),
				vector<bool>(m[0].size(),false));
    vector< vector<bool> > pac(m.size(),
				vector<bool>(m[0].size(),false));
    for(size_t i = 0; i < matrix.size(); ++i){
      for(size_t j = 0; j < matrix[i].size(); ++j){
	getPac(visit,pac,matrix[i][j],i,j);
      }
    }
    vector< vector<bool> > atl(matrix.size(),
				vector<bool>(matrix[0].size(),false));
    for(size_t i = matrix.size() - 1; i < matrix.size(); --i){
      for(size_t j = matrix[i].size() - 1; j < matrix[i].size(); --j){
	getAtl(matrix,atl,matrix[i][j],i,j);
      }
    }
    for(size_t i = 0; i < matrix.size(); ++i){
      for(size_t j = 0; j < matrix[i].size(); ++j){
	if(atl[i][j] && pac[i][j]) ans.push_back({i,j});
      }
    }
    return ans;
  }
private:
  vector< vector<int> > m;
  void getPac(vector<vector<bool> >& visit,
	      vector< vector<bool> >& flow,int val,int row,int col){
    if(row<0||row>=matrix.size()||col<0||col>=matrix[0].size()||
       visit[row][col]){
      return;
    }else{
      visit[row][col] = true;
      if(col == 0){
	flow[row][col] = true;
      }else if(row==0){
	flow[row][col] = true;
      }else{
	getPac
      }
    }
  }
  void getAtl(vector<vector<int> >& matrix,
	      vector< vector<bool> >& flow,int val,int row,int col){
    if(row<0||row>=matrix.size()||col<0||col>=matrix[0].size()||
       flow[row][col]){
      return;
    }else{
      if(col == matrix[0].size()-1){
	flow[row][col] = true;
      }else if(row== matrix.size() - 1){
	flow[row][col] = true;
      }else if(flow[row+1][col] <= flow[row][col] && flow[row+1][col]){
	flow[row][col] =true;
      }else if(flow[row][col+1] && flow[row][col+1] <= flow[row][col]){
	flow[row][col] = true;
      }else if(flow[row][col-1] && flow[row][col-1] <= flow[row][col]){
	flow[row][col] = true;
      }else if(flow[row+1][col] && flow[row+1][col] <= flow[row][col]){
	flow[row][col] = true;
      }
    }
  }
};
