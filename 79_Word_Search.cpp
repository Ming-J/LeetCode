#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool exist(vector< vector<char> >& board, string word){
    bool flag=false;
    vector< vector<bool> > visited(board.size(),
				   vector<bool> (board[0].size(),false));
    for(int i=0;i<board.size();i++){
      for(int j=0;j<board[i].size();j++){
	if(word[0]==board[i][j]){
	  vector< vector<bool> > temp;
	  temp=visied;
	  dfs(flag,board,i,j,1,word,temp);
	}
      }
    }
    return  flag;
  }

  void dfs(bool& flag,vector< vector<char> >& board, int row, int col,
	   int wordI, string word, vector<vector<bool> > &visit){
    if(row>=0&&row<board.size()&&col>=0&&col<board[row].size()
       &&!visit[row][col]&&!flag){
      if(board[row][col]==word[wordI]){
	visit[row][col]=true;
	if(wordI==word.size()-1){
	    flag=true;
	}else{
	  dfs(flag,board,row+1,col,wordI+1,word,visit);
	  dfs(flag,board,row-1,col,wordI+1,word,visit);
	  dfs(flag,board,row,col+1,wordI+1,word,visit);
	  dfs(flag,board,row,col-1,wordI+1,word,visit);
	}
      }
    }
  }
};
