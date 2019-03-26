#include <iostream>
using namespace std;

class Solution {
public:
  int clumsy(int N) {
    int ans = 0;
    while (N > 0) {
      int cur = 0;
      if (N > 0)
        cur = N--;
      if (N > 0)
        cur *= N--;
      if (N > 0)
        cur /= N--;
      ans = ans == 0 ? cur : ans - cur;
      if (N > 0)
        ans += N--;
    }
    return ans;
  }
};

int main() {
  Solution t;
  cout << t.clumsy(4) << endl;
}
