#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Connect4{
  vector<string> board;
  Connect4(){
    board = vector<string>(6,std::string(7,'.'));
  }
  void print(){
    for(auto it = board.rbegin(); it != board.rend(); ++it){
      cout<<*it<<endl;
    }
  }
  bool insert(char col, vector<string>& winCord){
    char piece = isupper(col)? 'X':'O';
    int start = 0;
    int colNum = toupper(col)-'A';
    while(board[start][colNum] != '.'){
      ++start;
    }
    board[start][colNum] = piece;
    return checkDiagonal(colNum,start,piece,winCord)||
      checkHorizontal(colNum,start,piece,winCord)||
      checkVertical(colNum,start,piece,winCord);
  }
  bool checkDiagonal(int col, int row, char p,vector<string>& winPosition){
    vector< pair<int,int> > coord = {make_pair(row,col)};
    int samepiece = 1;
    int newRow = row - 1;
    int newCol = col - 1;
    while(newRow>=0&&newRow<board.size()&&newCol>=0&&newCol<board[row].size()
	  &&board[newRow][newCol]==p&&
	  samepiece < 4){
      coord.push_back(make_pair(newRow--,newCol--));
      ++samepiece;
    }
    newRow=row+1;
    newCol=col+1;
    while(newRow>=0&&newRow<board.size()&&newCol>=0&&newCol<board[row].size()
	  &&board[newRow][newCol]==p&&
	  samepiece < 4){
      coord.push_back(make_pair(newRow++,newCol++));
      ++samepiece;
    }
    if(samepiece == 4){
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
    while(newCol>=0&&newCol<board[row].size()
	  &&board[row][newCol]==p&&
	  samepiece < 4){
      coord.push_back(make_pair(row,newCol--));
      ++samepiece;
    }
    newCol=col+1;
    while(newCol>=0&&newCol<board.size()&&board[row][newCol]==p&&
	  samepiece < 4){
      coord.push_back(make_pair(row,newCol++));
      ++samepiece;
    }
    if(samepiece == 4){
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
      coord.push_back(make_pair(newRow--,col));
      ++samepiece;
    }
    newRow=row+1;
    while(newRow>=0&&newRow<board.size()&&board[newRow][col]==p&&
	  samepiece < 4){
      coord.push_back(make_pair(newRow++,col));
      ++samepiece;
    }
    if(samepiece == 4){
      for(auto p : coord){
	winPosition.push_back(getCoordinate(p.first,p.second));
      }
    }
    return samepiece==4?true:false;
  }
  
  string getCoordinate(int row, int col){
    char c = static_cast<char>(col+'A');
    return c + to_string(row+1);
  }
};


int main(){
  Connect4 b;
  vector<pair<char,char> > moves = {
    {'D','d'},
    {'D','c'},
    {'C','c'},
    {'C','c'},
    {'G','f'},
    {'F','d'},
    {'F','f'},
    {'D','f'},
    {'A','a'},
    {'E','b'},
    {'E','e'},
    {'B','g'},
    {'G','g'},
    {'B','a'},
  };
  for(int i = 0; i < moves.size(); ++i){
    vector<string> win;
    if(b.insert(moves[i].first,win)
       ||b.insert(moves[i].second,win)){
      cout<<"Wining Moves: "<<i+1<<endl;
	for(auto s : win){
	cout<<s<<endl;
      }
      break;
    };
  }
  cout<<"ABCDEFG"<<endl;
  b.print();
  return 0;
}
