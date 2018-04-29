#include <iostream>
#include <vector>
using namespace std;

void check(const vector< vector<char> >& b, vector< vector<int> > &s,
	  int r, int c, const int k){
  vector< pair<int,int> > move = {{0,1},{1,0},{0,-1},{-1,0}};
  int ship = 0;
  for(size_t i = 0; i < move.size(); ++i){
    bool status = true;
    int x = r;
    int y = c;
    for(int j = 1; j < k; ++j){
      x += move[i].first;
      y += move[i].second;
      if(x<0 || x>=b.size() || y<0 || y >= b.size() ||b[x][y]=='#'){
	status = false;
	break;
      }
    }
    if(status){
      for(int j = 0; j < k; ++j){
	int x = r + move[i].first * j;
	int y = c + move[i].second * j;
	s[x][y] += 1;
      }
    } 
  }
}

int main(){
  int n,k;
  cin>>n>>k;
  vector< vector<char> > board(n,vector<char>(n,'#'));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      char c;
      cin>>c;
      board[i][j] = c;
    }
  }
  vector< vector<int> > sea(n,vector<int>(n,0));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(board[i][j] == '.'){
	check(board,sea,i,j,k);
      }
    }
  }
  int s = 0;
  int r = 1;
  int c = 1;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(sea[i][j] > s){
	r = i + 1;
	c = j + 1;
	s = sea[i][j];
      }
    }
  }
  cout<<r<<" "<<c<<endl;
}
