#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0,
                                  int color) {
    vector<vector<int>> next = grid;
    vector<vector<bool>> visited =
        vector(grid.size(), vector<bool>(grid[0].size(), false));
    int m = grid.size(), n = grid[0].size();
    dfs(next, grid, visited, m, n, r0, c0, grid[r0][c0], color);
    return next;
  }

private:
  void dfs(vector<vector<int>> &next, vector<vector<int>> &grid,
           vector<vector<bool>> visited, int m, int n, int r, int c,
           int old_color, int new_color) {
    if (0 <= r && r < m && 0 <= c && c < n && !visited[r][c] &&
        next[r][c] == old_color) {
      visited[r][c] = true;
      // Checking boundry
      if (checkBoundry(grid, m, n, r + 1, c, old_color) ||
          checkBoundry(grid, m, n, r - 1, c, old_color) ||
          checkBoundry(grid, m, n, r, c + 1, old_color) ||
          checkBoundry(grid, m, n, r, c - 1, old_color))
        next[r][c] = new_color;
      dfs(next, grid, visited, m, n, r + 1, c, old_color, new_color);
      dfs(next, grid, visited, m, n, r - 1, c, old_color, new_color);
      dfs(next, grid, visited, m, n, r, c + 1, old_color, new_color);
      dfs(next, grid, visited, m, n, r, c - 1, old_color, new_color);
    }
  }

  bool checkBoundry(vector<vector<int>> &next, int m, int n, int r, int c,
                    int old_color) {
    if (r < 0 || c < 0 || r > m - 1 || c > n - 1 || next[r][c] != old_color)
      return true;
    return false;
  }
};
