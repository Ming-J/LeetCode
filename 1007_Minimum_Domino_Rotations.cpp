#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int helper(vector<int> &A, int a, vector<int> &B, int b) {
    bool otherA = true, otherB = true;
    int nota = 0, notb = 0;
    for (int i = 0; i < A.size(); ++i) {
      if (A[i] != a) {
        nota++;
        if (B[i] != a) {
          otherA = false;
        }
      }
      if (B[i] != b) {
        notb++;
        if (A[i] != b) {
          otherB = false;
        }
      }
    }
    if (otherA && otherB) {
      return min(nota, notb);
    }
    if (otherA)
      return nota;
    if (otherB)
      return notb;
    return -1;
  }

  int minDominoRotations(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size())
      return -1;
    int one = helper(A, A.front(), B, B.front());
    int two = helper(A, B.front(), B, A.front());
    if (one == -1 && two == -1)
      return -1;
    if(one == -1)
      return two;
    if(two == -1)
      return one;
    return min(one.two);
  }
};

int main() {
  vector<int> a;
  vector<int> b;
  Solution t;
  cout << a.size() << ' ' << b.size() << endl;
  cout << t.minDominoRotations(a, b) << endl;
}
