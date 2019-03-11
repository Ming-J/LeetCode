#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int longestOnes(vector<int> &A, int K) {
    int lo = 0, hi = 0;
    for (hi = 0; hi < A.size(); ++hi) {
      if (A[hi] == 0)
        --K;
      if (K < 0 && A[lo++] == 0)
        ++K;
      cout << lo << ' ' << hi << ' ' << hi - lo << endl;
    }
    return hi - lo;
  }
};

int main() {
  vector<int> input = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
  int K = 0;
  Solution t;
  cout << t.longestOnes(input, K) << endl;
}