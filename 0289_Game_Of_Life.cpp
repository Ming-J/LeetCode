#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    vector<vector<int>> pre = board;
    for(int i = 0; i < board.size(); ++i){
      for(int j = 0; j < board[i].size(); ++j){
	board[i][j] = checkLive(i,j,board[i][j],pre) ? 1 : 0;
      }
    }
  }

private:
  bool checkLive(int i, int j,int islive, vector<vector<int>> &board) {
    vector<pair<int, int>> dir = {{-1, 1}, {0, 1},   {1, 1},  {-1, 0},
                                  {1, 0},  {-1, -1}, {0, -1}, {1, -1}};
    int live = 0;
    for (auto d : dir) {
      int r = d.first + i, c = d.second + j, n = board.size(),
          m = board[i].size();
      if (0 <= r && r < n && 0 <= c && c < m) {
        if (board[r][c] == 1)
          ++live;
      }
    }
    if(islive == 1){
      return (live == 2 || live == 3) ? true : false;
    }
    return live == 3 ? true : false;
  }
};
