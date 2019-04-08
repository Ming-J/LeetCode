#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int countDay(vector<int> &weights, int cap) {
    int count = 1;
    int cur_cap = 0;
    for (int w : weights) {
      cur_cap += w;
      if (cur_cap > cap) {
        ++count, cur_cap = w;
      }
    }
    return count;
  }

  int shipWithinDays(vector<int> &weights, int D) {
    int total = accumulate(weights.begin(), weights.end(), 0);
    int avg = max(total / D, *max_element(weights.begin(), weights.end()));
    while (avg < total) {
      int m = (total + avg) / 2;
      if (countDay(weights, m) <= D)
        total = m;
      else
        avg = m + 1;
    }
    return avg;
  }
};

int main() {
  vector<int> input = {3, 2, 2, 4, 1, 4};
  Solution t;
  cout << t.shipWithinDays(input, 3) << endl;
}
