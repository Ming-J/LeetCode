#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  int numSquarefulPerms(vector<int> &A) {
    unordered_set<int> sqr;
    vector<bool> used(A.size(), false);
    sort(A.begin(), A.end());
    for (size_t i = 1; i < sqrt(1e9); ++i)
      sqr.insert(i * i);
    vector<int> cur;
    int ans = 0;
    backtrack(A, used, sqr, ans, cur);
    return ans;
  }

private:
  unordered_set<string> seq;
  void backtrack(vector<int> &A, vector<bool> used, unordered_set<int> &sqr,
                 int &ans, vector<int> &cur) {
    if (cur.size() == A.size()) {
      ans++;
    } else {
      for (size_t i = 0; i < A.size(); ++i) {
        if (used[i])
          continue;
        if (i > 0 && !used[i] && A[i - 1] == A[i])
          continue;
        if (cur.empty() || sqr.find(cur.back() + A[i]) != sqr.end()) {
          cur.push_back(A[i]);
          backtrack(A, used, sqr, ans, cur);
          cur.pop_back();
        }
      }
    }
  }
};

int main() {
  for (int i = 0; i < (1 << 3); ++i) {
    cout << i << endl;
  }
}