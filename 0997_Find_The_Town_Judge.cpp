#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int findJudge(int N, vector<vector<int>> &trust) {
    vector<unordered_set<int>> ppl(N);
    vector<bool> trusting_other(N, false);
    for (auto t : trust) {
      ppl[t[1] - 1].insert(t[0] - 1);
      trusting_other[t[0] - 1] = true;
    }
    for (size_t i = 0; i < ppl.size(); ++i) {
      if (ppl[i].size() == N - 1 && !trusting_other[i])
        return i + 1;
    }
    return -1;
  }
};
