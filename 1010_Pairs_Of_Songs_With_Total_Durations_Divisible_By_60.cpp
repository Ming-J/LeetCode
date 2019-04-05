#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    if (time.size() <= 1)
      return 0;
    unordered_map<int, int> remainder;
    for (int n : time)
      ++remainder[n % 60];
    int ans = 0;
    for (int i = 0; i <= 30; ++i) {
      int rev_i = 60 - i;
      if (i == 0 || i == 30) {
        int total_count =
            (i == 0) ? remainder[i] + remainder[rev_i] : remainder[i];
        if (total_count)
          ans += (total_count * (total_count - 1)) / 2;
      } else {
        ans += remainder[i] * remainder[rev_i];
      }
    }
    return ans;
  }
};

int main() {
  vector<int> input = {30, 20, 150, 100, 40};
  Solution t;
  cout << t.numPairsDivisibleBy60(input) << endl;
}
