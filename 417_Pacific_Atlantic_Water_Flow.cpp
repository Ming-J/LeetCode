#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    m = matrix;
    vector<pair<int,int> > ans;
    if(matrix.size() == 0) return ans;
    vector< vector<bool> > pac(m.size(),
				vector<bool>(m[0].size(),false));
    vector< vector<bool> > atl(matrix.size(),
			       vector<bool>(matrix[0].size(),false));
    for(size_t i = 0; i < matrix.size(); ++i){
      getPac(pac,INT_MIN,i,0);
      getPac(atl,INT_MIN,i,matrix[0].size() - 1);
    }
    for(size_t i = 0; i < matrix[0].size(); ++i){
      getPac(pac,INT_MIN,0,i);
      getPac(atl,INT_MIN,matrix.size() - 1, i);
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
  void getPac(vector<vector<bool> >& visit,int val,int row,int col){
    if(row<0||row>=m.size()||col<0||col>=m[0].size()||
       visit[row][col] || m[row][col] < val){
      return;
    }else{
      visit[row][col] = true;
      getPac(visit,m[row][col],row+1,col);
      getPac(visit,m[row][col],row,col+1);
      getPac(visit,m[row][col],row-1,col);
      getPac(visit,m[row][col],row,col-1);
    }
  }
};
