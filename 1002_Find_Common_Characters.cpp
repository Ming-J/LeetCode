#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> commonChars(vector<string> &A) {
    vector<string> ans;
    vector<int> prev(26, 0);
    for (char c : A[0])
      ++prev[c-'a'];
    for (size_t i = 1; i < A.size(); ++i) {
      vector<int> cur(26, 0);
      for (char c : A[i])
        ++cur[c-'a'];
      for (size_t j = 0; j < cur.size(); ++j) {
        if (prev[j] > 0 && cur[j] > 0)
          prev[j] = min(prev[j], cur[j]);
        else
          prev[j] = 0;
      }
    }
    for (size_t i = 0; i < prev.size(); ++i) {
        ans.insert(ans.end(), prev[i], string(1, i + 'a'));
    }
    return ans;
  }
};
