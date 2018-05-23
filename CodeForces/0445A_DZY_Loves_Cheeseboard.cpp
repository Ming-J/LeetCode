#include <iostream>
#include <vector>
#include <string>
using namespace std;

void placeCheeseMan(vector<string>& board, int row, int col, char man){
  if(!(row>=0&&row<board.size()&&col>=0&&col<board[row].size()
      )||board[row][col]!= '.'){
    return;
  }
  board[row][col] = man;
  man = (man=='B')?'W':'B';
  placeCheeseMan(board,row+1,col,man);
  //placeCheeseMan(board,row-1,col,man);
  placeCheeseMan(board,row,col+1,man);
  //placeCheeseMan(board,row,col-1,man);
}

int main(){
  int n, m;
  cin>>n>>m;
  vector<string> board;
  for(int i =0 ; i < n; ++i){
    string str;
    cin>>str;
    board.push_back(str);
  }
  for(size_t i = 0; i < board.size(); ++i){
    for(size_t j = 0; j < board[i].size(); ++j){
      placeCheeseMan(board,i,j,'B');
    }
  }
  for(auto s : board){
    cout<<s<<endl;
  }
}
