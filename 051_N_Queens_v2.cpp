#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector< vector<string> > ans; 
    vector<string>board(n,string(n,'.'));
    backtracking(ans,0,board,0,0);
    return ans;
  }

  bool backtracking(vector<vector<string>>& ans,
		    int queen,
		    vector<string>& board,int row, int col){
    if(queen == board.size()){
      ans.push_back(board);
      return true;
    }else{
      for(int i = row; i < board.size(); ++i){
	for(int j = 0; j < board[i].size(); ++j){
	  if(queenCheck(board,i,j)){
	    board[i][j] = 'Q';
	    backtracking(ans,queen+1,board,i+1,j);
	    board[i][j] = '.';
	  }
	}
      }
    }
    return true;
  }
  

private:
  bool queenCheck(vector<string>& board,
		  int row, int col){
    if(board[row][col] != '.') return false;
    for(int i = col - 1; i >= 0; --i){
      if(board[row][i] != '.') return false;
    }
    for(int i = col + 1; i < board[row].size(); ++i){
      if(board[row][i] != '.') return false;
    }
    for(int i = row - 1; i >= 0; --i){
      if(board[i][col] != '.') return false;
    }
    for(int i = row + 1; i < board.size(); ++i){
      if(board[i][col] != '.') return false;
    }
    vector< pair<int,int> > dia = {{1,1},{1,-1},{-1,-1},{-1,1}};
    for(auto curDia : dia){
      for(int i = row+curDia.first, j = col+curDia.second;
	  i>=0&&i<board.size()&&j>=0&&j<board[row].size();){
	if(board[i][j] != '.') return false;
	i+=curDia.first;
	j+=curDia.second;
      }
    }
    return true;
  }
};
