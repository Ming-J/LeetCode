#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Connect4{
  vector<string> board;
  Connect4(){
    board = vector<string>(6,std::string(7,'.'));
  }
  bool insert(char col){
    char piece = isupper(col)? 'X':'O';
    int start = 0;
    int colNum = toupper(col)-'A';
    while(board[start][colNum] != '.'){
      ++start;
    }
    board[start][colNum] = piece;
    vector<string> winCoord;
    return checkDiagonal(colNum,start,piece,winCoord)||
      checkHorizontal(colNum,start,piece,winCoord)||
      checkVertical(colNum,start,piece,winCoord);
  }
  bool checkDiagonal(int col, int row, char p,vector<string>& winPosition){
    vector< pair<int,int> > coord = {make_pair(row,col)};
    int samepiece = 1;
    int newRow = row - 1;
    int newCol = col - 1;
    while(newRow>=0&&newRow<board.size()&&newCol>=0&&newCol<board[row].size()
	  &&board[newRow][newCol]==p&&
	  samepiece < 4){
      coord.insert(make_pair(newRow--,newCol--));
      ++samepicee;
    }
    newRow=row+1;
    newCol=col+1;
    while(newRow>=0&&newRow<board.size()newCol>=0&&newCol<board[row].size()
	  &&board[newrow][newCol]!=p&&
	  samepiece < 4){
      coord.insert(make_pair(newRow++,newCol++));
      ++samepiece;
    }
    if(samepiece = 4){
      for(auto p : coord){
	winPosition.push_back(getCoordinate(p.first,p.second));
      }
    }
    return samepiece==4?true:false;
  }
  
  bool checkHorizontal(int col, int row, char p,vector<string>& winPosition){
    vector< pair<int,int> > coord = {make_pair(row,col)};
    int samepiece = 1;
    int newCol = col - 1;
    while(newCol>=0&&newCol<board[row].size()&&board[row][newCol]==p&&
	  samepiece < 4){
      coord.insert(make_pair(row,NewCol--));
      ++samepicee;
    }
    newCol=col+1;
    while(newRow>=0&&newRow<board.size()&&board[row][newCol]!=p&&
	  samepiece < 4){
      coord.insert(make_pair(row,NewCol++));
      ++samepiece;
    }
    if(samepiece = 4){
      for(auto p : coord){
	winPosition.push_back(getCoordinate(p.first,p.second));
      }
    }
    return samepiece==4?true:false;
  }

  bool checkVertical(int col, int row, char p,vector<string>& winPosition){
    vector< pair<int,int> > coord = {make_pair(row,col)};
    int samepiece = 1;
    int newRow = row - 1;
    while(newRow>=0&&newRow<board.size()&&board[newRow][col]==p&&
	  samepiece < 4){
      coord.insert(make_pair(newRow--,col));
      ++samepicee;
    }
    newRow=row+1;
    while(newRow>=0&&newRow<board.size()&&board[newrow][col]!=p&&
	  samepiece < 4){
      coord.insert(make_pair(newRow++,col));
      ++samepiece;
    }
    if(samepiece = 4){
      for(auto p : coord){
	winPosition.push_back(getCoordinate(p.first,p.second));
      }
    }
    return samepiece==4?true:false;
  }
  
  string getCoordinate(int row, int col){
    char c = static_cast<char>(col+'A');
    return c + to_string(row);
  }
};


int main(){
  return 0;
}
