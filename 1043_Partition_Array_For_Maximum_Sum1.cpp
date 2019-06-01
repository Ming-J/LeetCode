#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &A, int K) { return rec(A, K, 0); }

  int rec(vector<int> &A, int K, int lo) {
    if (lo >= A.size())
      return 0;
    int maxV = numeric_limits<int>::min();
    for (int i = 0; i < K && lo + i < A.size(); ++i) {
      int cur = 0;
      auto it = memo.find({lo, lo + i});
      if (it == memo.end()) {
        cur = maxCheck(A, lo, lo + i) * (i + 1);
        memo.insert({{lo, lo + i}, cur});
      } else {
        cur = it->second;
      }
      auto nex = map.find(lo + i + 1);
      int next = 0;
      if (nex == map.end()) {
        next = rec(A, K, lo + i + 1);
        map.insert({lo + i + 1, next});
      } else {
        next = nex->second;
      }
      maxV = max(maxV, cur + next);
    }
    return maxV;
  }

private:
  map<pair<int, int>, int> memo;
  unordered_map<int, int> map;
  int maxCheck(vector<int> &A, int lo, int hi) {
    hi = A.size() <= hi ? A.size() : hi + 1;
    for (int i = lo; i < hi; ++i) {
      cout << A[i] << ' ';
    }
    cout << endl;
    return *max_element(A.begin() + lo, A.begin() + hi);
  }
};

int main() {
  vector<int> input = {1, 15, 7, 9, 2, 5, 10};
  Solution t;
  cout << t.maxSumAfterPartitioning(input, 3) << endl;
}
