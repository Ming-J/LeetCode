#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
  double knightProbability(int N, int K, int r, int c) {
    vector<vector<double> > board( N, vector<double> (N, 0) );
    vector<pair<int,int> > moves = {{2,1},{2,-1},{1,2},{1,-2}
				  ,{-2,1},{-2,-1},{-1,2},{-1,-2}};
    board[r][c] = 1.0;
    for( int i = 0 ; i < K; i++){
      nextMove(board,moves);
    }
    return countMoves(board);
  }
  bool validmove( int r, int c, int x, int y, int N){
    int newr = r + x;
    int newy = c + y;
    return (newr >= 0 && newr < N && newy >= 0 && newy < N)? true : false;
  }
  double countMoves( vector< vector<double> > &board){
    double cnt = 0.0;
    for( int i = 0; i < board.size(); i++){
      for( int j = 0; j < board[i].size(); j++){
	if( board[i][j] > 0 ){
	  cnt += board[i][j];
	}
      }
    }
    return cnt;
  }

  void nextMove(vector<vector<double> > &board, vector< pair<int, int> > moves){
    vector<vector<double> >newboard(board.size(),vector<double>(board.size(),0.0));
    for( int i = 0; i < board.size(); i++){
      for( int j = 0; j < board[i].size(); j++){
	if(board[i][j] > 0){
	  double duplicateMoves = board[i][j];
	  board[i][j] = 0.0;
	  for( int k = 0; k < moves.size(); k++){
	    if(validmove(i,j,moves[k].first, moves[k].second, board.size())){
	      newboard[i+moves[k].first][j+moves[k].second] += (duplicateMoves/8.0);
	    }
	  }
	}
      }
    }
    board = newboard;
    return;
  }
};


int main(){
  Solution test;
  cout<<test.knightProbability(8,30,6,4);
}

