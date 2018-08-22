#include <iostream>
using namespace std;

class Solution {
public:
  void solveSudoku(vector<vector<char>>& board) {
    backTrack(board);
  }

  bool backTrack(vector<vector<char> >& board){
    for(size_t i = 0; i < board.size(); ++i){
      for(size_t j = 0; j < board[i].size(); ++j){
	if(board[i][j] == '.'){
	  for(int k = 0; k < 10; ++k){
	    if(checkRow(board,j,i,k)
	       &&checkCol(board,j,i,k)
	       &&checkBox(board,j,i,k)){
	      board[i][j] = k+'0';
	      if(backTrack(board)){
		return true;
	      }else{
		board[i][j]='.';
	      }
	    }
	  }
	  return false;
	}
      }
    }
    return true;
  }
  


private:
  void hintBoard(vector<vector<char> > & board,
		 vector<vector<bool> >& hints){
    for(size_t i = 0; i < board.size(); ++i){
      for(size_t j = 0; j < board[i].size(); ++j){
	hints[i][j] = (board[i][j]=='.')?false:true;
      }
    }
  }
  bool checkRow(vector<vector<char> >& board, int c, int r,int val){
    for(char i :  board[r]){
      if(i!='.' && i-'0' == val)
	return false; 
      }
    return true;
  }
  
  bool checkCol(vector<vector<char> >& board, int c, int r, int val){
    for(vector<char> arr :  board){
      if(arr[r]!='.' && arr[r] - '0' == val)
	return false; 
      }
    return true;
  }
  void checkHiLo(int i, int &lo, int &hi){
    if(i<3){
      lo=0;
      hi=3;
    }else if(i<6){
      lo=3;
      hi=6;
    }else{
      lo=6;
      hi=9;
    }
  }
  bool checkBox(vector<vector<char> >& board, int c, int r,int val){
    int rLo, rHi, cLo, cHi;
    checkHiLo(r,rLo,rHi);
    checkHiLo(c,cLo,cHi);
    for(size_t i = rLo; i < rHi; ++i){
      for(size_t j = cLo; j < cHi; ++j){
	char k = board[i][j];
	if(k!='.' && k - '0' == val){
	  return false;
	}
      }
    }
    return true;
  }

};
