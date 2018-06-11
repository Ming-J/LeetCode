#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      for(int i = 0; i < board.size(); ++i){
	if(!checkRow(board,i)||!checkCol(board,i)||
	   !checkBox(board,i+1)) return false;
      }
      return true;
    }    
    
    bool checkRow(vector<vector<char> >& board, int row){
        vector<bool> validNumber(board[row].size(),false);
        for(size_t i = 0; i < board[row].size(); ++i){
	  if(board[row][i]!='.'){
	    int val = board[row][i] - '1';
	    if(validNumber[val]) return false;
            validNumber[val] = true;
	  }
	}
        return true;
    }
    
    bool checkCol(vector<vector<char> >& board, int col){
        vector<bool> validNumber(board.size(),false);
        for(size_t i = 0; i < board.size(); ++i){
	  if(board[i][col]!='.'){
            int val = board[i][col] - '1';
            if(validNumber[val]) return false;
            validNumber[val] = true;
	  }
	}
        return true;
    }
    bool checkBox(vector<vector<char> >& board, int box){
        vector<bool> validNumber(board.size(),false);
        int row, col;
	if(box == 1 || box == 4 || box == 7) row = 0;
	if(box == 2 || box == 5 || box == 8) row = 3;
	if(box == 3 || box == 6 || box == 9) row = 6;
	if(box == 1 || box == 2 || box == 3) col = 0;
	if(box == 4 || box == 5 || box == 6) col = 3;
	if(box == 7 || box == 8 || box == 9) col = 6;
        for(size_t i = row; i < row+3; ++i){
	  for(size_t j = col; j < col+3; ++j){
	     if(board[i][j]!='.'){
	       int val = board[i][j] - '1';
	       if(validNumber[val]) return false;
	       validNumber[val] = true;
	     }
	  }
	}
        return true;
    }
};
