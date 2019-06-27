#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    int maxVal = 0;
    unordered_map<string, int> pos;
    for (auto row : matrix) {
      pair<string, string> strs = convertRow(row);
      maxVal = max(maxVal, (++pos[strs.first] + ++pos[strs.second]) / 2);
    }
    return maxVal;
  }

  pair<string, string> convertRow(vector<int> &row) {
    string pos = "", neg = "";
    for (int i : row) {
      pos.push_back(i + '0');
      neg.push_back((i ? 0 : 1) + '0');
    }
    return {pos, neg};
  }
};

int main() { cout << "hi" << endl; }
