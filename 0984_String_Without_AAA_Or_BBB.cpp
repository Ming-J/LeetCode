#include <iostream>
#include <string>
using namespace std;

/*
   aaaa bb
*/
class Solution {
public:
  string strWithout3a3b(int A, int B, char a = 'a', char b = 'b') {
    string res;
    if (B > A) {
      swap(A, B);
      swap(a, b);
    }
    while (A > 0 || B > 0) {
      if (A > 0) {
        res += a;
        A--;
      }
      if (A > B) {
        res += a;
        A--;
      }
      if (B > 0) {
        res += b;
        B--;
      }
    }
    return res;
  }
};

int main() {
  Solution t;
  cout << t.strWithout3a3b(4, 1) << endl;
}