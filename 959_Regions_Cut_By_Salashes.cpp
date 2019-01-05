#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int regionsBySlashes(vector<string> &grid) {
    int size = grid.size() * 3;
    vector<vector<int>> island(size, vector<int>(size, 0));
    for (size_t i = 0, island_r = 0; i < grid.size(); ++i, island_r += 3) {
      for (size_t j = 0, island_c = 0; j < grid[i].size(); ++j, island_c += 3) {
        modifyIsland(island, island_r, island_c, grid[i][j]);
      }
    }
    vector<vector<bool>> visited(size, vector<bool>(size, false));
    int region = 0;
    for (size_t i = 0; i < island.size(); ++i) {
      for (size_t j = 0; j < island[i].size(); ++j) {
        if (!visited[i][j] && island[i][j] == 0) {
          ++region;
          numbofIsland(island, visited, i, j);
        }
      }
    }
    return region;
  }

private:
  void numbofIsland(vector<vector<int>> &island, vector<vector<bool>> &visited,
                    int r, int c) {
    if (r < 0 || r >= island.size() || c < 0 || c >= island.size() ||
        visited[r][c] || island[r][c] == 1)
      return;
    visited[r][c] = true;
    numbofIsland(island, visited, r + 1, c);
    numbofIsland(island, visited, r - 1, c);
    numbofIsland(island, visited, r, c + 1);
    numbofIsland(island, visited, r, c - 1);
  }

  void modifyIsland(vector<vector<int>> &island, int row, int col, char c) {
    if (c == '\\') {
      island[row][col] = 1;
      island[row + 1][col + 1] = 1;
      island[row + 2][col + 2] = 1;
    }
    if (c == '/') {
      island[row][col + 2] = 1;
      island[row + 1][col + 1] = 1;
      island[row + 2][col] = 1;
    }
  }
};

int main() {
  Solution t;
  vector<string> input = {"\\/", "/\\"};
  cout << endl << t.regionsBySlashes(input);
}