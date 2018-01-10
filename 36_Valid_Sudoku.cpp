#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:
  bool isValidSudoku(vector<vector<char> >& board){
    if(board.size()!=9||board[0].size()!=9){
      return false;
    }
    bool ans=true;
    for(int i=0;i<9;i++){
      ans=ans&&checkrow(board,i)&&checkcol(board,i)&&checkbox(board,i);
    }
    return ans;
  }

  bool checkrow(vector<vector< char> >& board,int row){
    int hash[9]={0};
    for(int i=0;i<board[row].size();i++){
      if(board[row][i]!='.'){
	int d=(board[row][i]-'0')-1;
	if(hash[d]!=0){
	  return false;
	}
	hash[d]++;
      }
    }
    return true;
  }
  bool checkcol(vector<vector< char> >& board,int col){
    int hash[9]={0};
    for(int i=0;i<board.size();i++){
      if(board[i][col]!='.'){
	int d=(board[i][col]-'0')-1;
	if(hash[d]!=0){
	  return false;
	}
	hash[d]++;
      }
    }
    return true;
  }
  bool checkbox(vector<vector< char> >& board,int box){
    int row1,row2,col1,col2;
    boxBoundary(box,row1,row2,col1,col2);
    int hash[9]={0};
    for(int i=row1;i<=row2;i++){
      for(int j=col1;j<=col2;j++){
	if(board[i][j]!='.'){
	  int d=(board[i][j]-'0')-1;
	  if(hash[d]!=0){
	    return false;
	  }
	  hash[d]++;
	}
      }
    }
    return true;
  }
  
  void boxBoundary(int box,int &row1,int &row2,int &col1, int &col2){
    if(box==0||box==1||box==2){
      row1=0;
      row2=2;
    }
    if(box==3||box==4||box==5){
      row1=3;
      row2=5;
    }
    if(box==6||box==7||box==8){
      row1=6;
      row2=8;
    }
    if(box==0||box==3||box==6){
      col1=0;
      col2=2;
    }
    if(box==1||box==4||box==7){
      col1=3;
      col2=5;
    }
    if(box==2||box==5||box==8){
      col1=6;
      col2=8;
    }
    return;
  }
};
