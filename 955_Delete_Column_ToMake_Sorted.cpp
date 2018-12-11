#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minDeletionSize(vector<string> &A) {
    int ans = 0, n = A.size(), m = A.front().size(), i, j;
    vector<bool> sorted(A.size() - 1, false);
    for (i = 0; i < A.front().size(); ++i) {
      for (j = 0; j < A.size() - 1; ++j) {
        if (!sorted[j] && A[j][i] > A[j + 1][i]) {
          ++ans;
          break;
        }
      }
      if (j < A.size() - 1)
        continue;
      for (j = 0; j < A.size() - 1; ++j) {
        if (A[j][i] < A[j + 1][i]) {
          sorted[j] = true;
        }
      }
    }
    return ans;
  }
};

int main() { return 1; }