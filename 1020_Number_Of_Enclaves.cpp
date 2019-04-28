#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numEnclaves(vector<vector<int>> &A) {
    int total = 0, walk = 0;
    vector<vector<bool>> visited(A.size(),
                                 vector<bool>(A.front().size(), false));
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < A[i].size(); ++j) {
        if (A[i][j] == 1) {
          ++total;
          if ((i == 0 || i == A.size() - 1 || j == 0 || j == A[i].size() - 1) &&
              !visited[i][j])
            helper(i, j, A, visited, walk);
        }
      }
    }
    cout<<total<<endl;
    return total - walk;
  }

  void helper(int rol, int col, vector<vector<int>> &A,
              vector<vector<bool>> &visited, int &walk) {
    if (rol >= 0 && rol < A.size() && col >= 0 && col < A[rol].size() &&
        A[rol][col] == 1 && !visited[rol][col]) {
      ++walk;
      visited[rol][col] = true;
      helper(rol + 1, col, A, visited, walk);
      helper(rol - 1, col, A, visited, walk);
      helper(rol, col + 1, A, visited, walk);
      helper(rol, col - 1, A, visited, walk);
    }
  }
};

int main() {
  vector<vector<int>> input = {
      {0, 0, 0, 1, 1, 1, 0, 1, 0, 0}, {1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
      {0, 0, 0, 1, 1, 1, 0, 1, 0, 0}, {0, 1, 1, 0, 0, 0, 1, 0, 1, 0},
      {0, 1, 1, 1, 1, 1, 0, 0, 1, 0}, {0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
      {0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, {0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
      {1, 0, 1, 0, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0, 0, 1}};
  Solution t;
  cout << t.numEnclaves(input) << endl;
  cout << "sd" << endl;
}
