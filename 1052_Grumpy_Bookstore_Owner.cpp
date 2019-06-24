#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
    // First calculate the number of satisfied
    int satisfied = 0;
    for (size_t i = 0; i < customers.size(); ++i) {
      if (!grumpy[i])
        satisfied += customers[i];
    }
    // Use sliding window to find the best technique
    int maxSatisfied = 0;
    for (size_t lo = 0, hi = 0, count = 0; hi < customers.size(); ++lo, ++hi) {
      if (count < X) {
        while (count++ < X)
          satisfied += (!grumpy[hi]) ? 0 * customers[hi++] : customers[hi++];
        --hi;
      } else {
        satisfied -= !grumpy[lo - 1] ? 0 : customers[lo - 1];
        satisfied += !grumpy[hi] ? 0 : customers[hi];
      }
      maxSatisfied = max(maxSatisfied, satisfied);
    }
    return maxSatisfied;
  }
};
/*
  Time Complexity: O(N)
  Space Complexity : S(1)
*/
int main() {
  vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
  vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
  Solution s;
  cout << s.maxSatisfied(customers, grumpy, 3) << endl;
}
