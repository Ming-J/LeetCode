#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        int count = 0;
        helper(grid, count);
        return count;
    }

  private:
    void helper(vector<vector<int>> board, int &count) {
        vector<vector<int>> newBoard(board);
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[i].size(); ++j) {
                for (auto d : dir) {
                    int x = d.first + i, y = d.second + j;
                    if (x >= 0 && x < board.size() && y >= 0 &&
                        y < board[x].size() && board[i][j] == 2 &&
                        newBoard[x][y] == 1) {
                        newBoard[x][y] = 2;
                    }
                }
            }
        }
        bool isDif = false, isFresh = false;
        for (size_t i = 0; i < newBoard.size(); ++i) {
            for (size_t j = 0; j < newBoard[i].size(); ++j) {
                if (newBoard[i][j] == 1)
                    isFresh = true;
                if (newBoard[i][j] != board[i][j])
                    isDif = true;
            }
        }
        if (isDif)
            ++count;
        if (!isDif && !isFresh) {
            count = -1;
            return;
        } else if (!isDif) {
            return;
        }
        helper(newBoard, count);
    }
};