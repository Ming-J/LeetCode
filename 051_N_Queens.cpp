#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector< vector<string> > ans;
    board.assign(n,string(n,'.'));
    rows.assign(n,0);
    columns.assign(n,0);
    diag1.assign(n*2-1,0);
    diag2.assign(n*2-1,0);
    backtrack(ans,0,0,0);
    cout<<ans.size()<<endl;;
    for(auto str : ans){
      print(str);
      cout<<endl;
    }
    return ans;
  }
  void backtrack(vector<vector<string> > &ans, int n, int row, int col){
    if(n == board.size()){
      ans.push_back(board);
      return;
    }
    for(size_t i = row; i < board.size(); ++i){
      for(size_t j = 0; j < board[i].size(); ++j){
	if(checkH(i,j)&&checkV(i,j)&&checkDia(i,j)&&board[i][j]!='Q'){
	  board[i][j] = 'Q';
	  rows[i]=1;
	  columns[j]=1;
	  diag1[i+j]=1;
	  diag2[i-j+board.size()-1]=1;
	  backtrack(ans,n+1,i+1,j);
	  rows[i]=0;
	  columns[j]=0;
	  diag1[i+j]=0;
	  diag2[i-j+board.size()-1]=0;
	  board[i][j] = '.';
	}
      }
    }
  }
private:
  vector<string> board;
  vector<int> rows;
  vector<int> columns;
  vector<int> diag1;
  vector<int> diag2;
  bool checkH(int row, int col){
    if(columns[col] == 1){
      return false;
    }
    return true;
  }
  bool checkV(int row, int col){
    if(rows[row] == 1){
      return false;
    }
    return true;
  }
  bool checkDia(int row, int col){
    if(diag1[row+col]==1||diag2[row-col+board.size()-1]==1){
      return false;
    }
    return true;
  }
  void print(vector<string> b){
    for(auto i : b){
      cout<<i<<endl;
    }
  }
};


int main(){
  vector< vector<string> > ans;
  Solution test;
  ans = test.solveNQueens(4);
}
