#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    int needToWalk = 0;
    pair<int, int> startPoint;
    //Looking for starting point and Cell need to walk
    for (size_t i = 0; i < grid.size(); ++i) {
      for (size_t j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == 0)
          ++needToWalk;
        else if (grid[i][j] == 1)
          startPoint = make_pair(j, i);
      }
    }
    int unique = 0;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    //Starting from the four cell adjcent to starting point
    for (auto dir : directions) {
      path(grid, unique, needToWalk, startPoint.first + dir.first,
           startPoint.second + dir.second);
    }
    return unique;
  }

private:
  void path(vector<vector<int>> &grid, int &paths, int walked, int c, int r) {
    // make sure we are inside the grid
    if (r >= 0 && r < grid.size() && c >= 0 && c < grid[r].size()) {
      if (grid[r][c] == -1 || grid[r][c] == 3 || grid[r][c] == 1) //checking to see if it's a valid cell
        return;
      if (grid[r][c] == 2) {
        if (walked == 0)
          ++paths;
        return;
      }
      cout << r << ' ' << c << ' ' << walked << endl;
      vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
      for (auto dir : directions) {
        grid[r][c] = 3;
        path(grid, paths, walked - 1, c + dir.first, r + dir.second);
        grid[r][c] = 0;
      }
    }
  }
};

int main() {
  vector<vector<int>> grid = {{0, 1}, {2, 0}};
  Solution test;
  cout << test.uniquePathsIII(grid) << endl;
  cout << "HEllo" << endl;
}
