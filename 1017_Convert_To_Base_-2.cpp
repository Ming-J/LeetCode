#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
  string baseNeg2(int N) {
    if (N == 0)
      return "0";
    string negBinary;
    while (N != 0) {
      negBinary += (N % -2 == 0) ? "0" : "1";
      N = (N % -2 < 0) ? (N / -2) + 1 : N / -2;
      cout << "N is " << N << endl;
    }
    reverse(negBinary.begin(), negBinary.end());
    return negBinary;
  }
};

int main() {
  cout << 146 / -3 << " " << 146 % -3 << endl;
  cout << -5 / -3 << " " << -5 % -3 << endl;
  cout << 3 / -2 << " " << -5 % -3 << endl;
  Solution t;
  cout << "8: " << t.baseNeg2(8) << endl;
  cout << "2: " << t.baseNeg2(2) << endl;
  cout << "3: " << t.baseNeg2(3) << endl;
  cout << "Hello" << endl;
}
