#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// R,  p
class Solution {
  public:
    int numRookCaptures(vector<vector<char>> &board) {
        int rock_r, rock_c;
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'R')
                    rock_r = i, rock_c = j;
            }
        }
        int ans = 0;
        for (size_t i = rock_r - 1; i < rock_r; --i) {
            if (board[i][rock_c] != '.') {
                ans += (board[i][rock_c] == 'p') ? 1 : 0;
                break;
            }
        }
        for (size_t i = rock_r + 1; i < board.size(); ++i) {
            if (board[i][rock_c] != '.') {
                ans += (board[i][rock_c] == 'p') ? 1 : 0;
                break;
            }
        }
        for (size_t i = rock_c - 1; i < rock_c; --i) {
            if (board[rock_r][i] != '.') {
                ans += (board[rock_r][i] == 'p') ? 1 : 0;
                break;
            }
        }
        for (size_t i = rock_c + 1; i < board[rock_r].size(); ++i) {
            if (board[rock_r][i] != '.') {
                ans += (board[rock_r][i] == 'p') ? 1 : 0;
                break;
            }
        }
        return ans;
    }
};