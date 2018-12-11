#include <iostream>
#include <limits>
using namespace std;

/*
  n people

*/

int main() {
  // freopen_s("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int n;
  long long int row;
  cin >> n >> row;
  int strongest;
  cin >> strongest;
  long long int in_row = 0;
  for (int i = 0; i < n - 1; ++i) {
    int p;
    cin >> p;
    if (strongest > p) {
      ++in_row;
    } else {
      in_row = 1;
      strongest = p;
    }
    if (in_row == row) {
      cout << strongest << endl;
      return 0;
    }
  }
  cout << strongest << endl;
  return 0;
}
