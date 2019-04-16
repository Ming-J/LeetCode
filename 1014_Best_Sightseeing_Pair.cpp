#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &A) {
    int res = 0, cur = 0;
    for (int a : A) {
      res = max(res, cur + a);
      cur = max(cur, a) - 1;
    }
    return res;
  }
};

int main() {
  vector<int> input = {9, 7, 6, 7, 6, 9};
  Solution S;
  cout << S.maxScoreSightseeingPair(input) << endl;
  cout << "S" << endl;
}
