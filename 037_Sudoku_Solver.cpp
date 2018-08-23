#include <iostream>
#include <vector>
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
	  for(int k = 1; k < 10; ++k){
	    if(checkRow(board,j,i,k)
	       &&checkCol(board,j,i,k)
	       &&checkBox(board,j,i,k)){
	      board[i][j] = k + '0';
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
  
  bool checkRow(vector<vector<char> >& board, int c, int r,int val){
    for(char i :  board[r]){
      if(i!='.' && i-'0' == val)
	return false; 
    }
    return true;
  }
  
  bool checkCol(vector<vector<char> >& board, int c, int r, int val){
    for(vector<char> arr :  board){
      if(arr[c]!='.' && arr[c] - '0' == val)
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


int main(){
  vector<vector<char> > board={{'5','3','.','.','7','.','.','.','.'},
			       {'6','.','.','1','9','5','.','.','.'},
			       {'.','9','8','.','.','.','.','6','.'},
			       {'8','.','.','.','6','.','.','.','3'},
			       {'4','.','.','8','.','3','.','.','1'},
			       {'7','.','.','.','2','.','.','.','6'},
			       {'.','6','.','.','.','.','2','8','.'},
			       {'.','.','.','4','1','9','.','.','5'},
			       {'.','.','.','.','8','.','.','7','9'}};
  Solution test;
  test.solveSudoku(board);
  cout<<"Slove"<<endl;
  for(size_t i = 0; i < board.size(); ++i){
    for(size_t j = 0; j < board[i].size(); ++j){
      cout<<board[i][j];   
    }
    cout<<endl;
  }
  cout<<endl;
}
