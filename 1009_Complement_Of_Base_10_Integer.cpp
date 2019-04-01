#include <iostream>
using namespace std;

class Solution {
public:
  int bitwiseComplement(int N) {
    int m;
    for (m = 1; N > m; m = (m << 1) + 1) {
    }
    return m ^ N;
  }
};

int main() {

  Solution t;
  cout << t.bitwiseComplement(5) << endl;
  cout << t.bitwiseComplement(7) << endl;
  cout << t.bitwiseComplement(10) << endl;

  int n = 1;

  for (int i = 0; i < 30; ++i) {
    cout << i << ' ' << n << endl;
    n = n << 1;
  }

  int j = 1 << 30;
  for (int i = 30; i >= 0; --i) {
    cout << i << ' ' << j << endl;
    j = j >> 1;
  }
}
