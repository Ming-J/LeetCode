#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
  double knightProbability(int N, int K, int r, int c) {
    vector<vector<int> > board( N, vector<int> (N, 0) );
    vector<pair<int,int> > moves = {{2,1},{2,-1},{1,2},{1,-2}
				  ,{-2,1},{-2,-1},{-1,2},{-1,-2}};
    vector<vector<int> > prob = board;
    board[r][c] = 1;
    for( int i = 0 ; i < K; i++){
      nextMove(board,moves);
      print(board);
      cout<<endl;
      copyProb(prob,board);
    }
    cout<<endl;
    int possible = countMoves(prob);
    print(prob);
    int allmoves = pow(8,K);
    cout<<allmoves;
    return possible;
  }
  bool validmove( int r, int c, int x, int y, int N){
    int newr = r + x;
    int newy = c + y;
    if( newr >= 0 && newr < N && newy >= 0 && newy < N){
      return true;
    }
    return false;
  }
  void copyProb( vector< vector<int> > &prob, vector< vector<int> > &board){
    for( int i = 0; i < board.size(); i++){
      for( int j = 0; j < board[i].size(); j++){
	if( board[i][j] == 1 ){
	  prob[i][j] = 1;
	}
      }
    }
  }
  int countMoves( vector< vector<int> > &board){
    int cnt = 0;
    for( int i = 0; i < board.size(); i++){
      for( int j = 0; j < board[i].size(); j++){
	if( board[i][j] == 1 ){
	  cnt++;
	}
      }
    }
    return cnt;
  }

  void nextMove( vector< vector<int> > &board, vector< pair<int, int> > moves, int &cnt){
    vector<vector<int> > newboard( board.size(), vector<int> (board.size(),0));
    for( int i = 0; i < board.size(); i++){
      for( int j = 0; j < board[i].size(); j++){
	if(board[i][j] == 1){
	  board[i][j] = 0;
	  for( int k = 0; k < moves.size(); k++){
	    if(validmove(i,j,moves[k].first, moves[k].second, board.size())){
	      newboard[i+moves[k].first][j+moves[k].second] = 1;
	    }
	  }
	}
      }
    }
    board = newboard;
    return;
  }
  void print( vector< vector<int> > &board){
    for( int i = 0; i < board.size(); i++){
      for( int j = 0; j < board[i].size(); j++){
	cout<<board[i][j];
      }
      cout<<endl;
    }
  }  
};


int main(){
  Solution test;
  cout<<test.knightProbability(3,2,0,0);
}
