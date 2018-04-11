#include <iostream>
#include <vector>
using namespace std;
/*
  Time: O(n*n)
  Space: O(n*n)
*/
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector< vector<int> > m(n,vector<int> (n,0));
    vector<pair<int,int> > moves = {{0,1},{1,0},{0,-1},{-1,0}};
    int val = 1;
    int action = 0;
    int row = 0;
    int col = 0;
    while(val < m.size() * m.size() + 1){
      if(row<0||row>=m.size()||col<0||col>=m.size()||m[row][col] != 0){
	row -= moves[action].first;
	col -= moves[action].second;
	++action %= 4;
      }else{
	m[row][col] = val++;
      }
      row += moves[action].first;
      col += moves[action].second;
    }
    return m;
  }
private:
  void sprial(vector<vector<int> > &m,const vector<pair<int,int> > moves,
	      int &val, int row , int col,int &action){
    if(val == m.size() * m.size() + 1){
      return;
    }else if(row<0||row>=m.size()||col<0||col>=m.size()||m[row][col] != 0){
      row -= moves[action].first;
      col -= moves[action].second;
      ++action %= 4;
      sprial(m,moves,val,row+moves[action].first,col+moves[action].second,action);
      return;
    }else{
      m[row][col] = val++;
      sprial(m,moves,val,row+moves[action].first,col+moves[action].second,action);
    }
  }
};

int main(){
  Solution test;
  vector< vector<int> > m =test.generateMatrix(5);
  for(auto i : m){
    for(auto j : i){
      cout<<j<<' ';
    }
    cout<<endl;
  }
}
