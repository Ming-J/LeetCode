#include <iostream>
#include <string>
using namespace std;

string winner(int s, int v1, int v2, int t1, int t2) {
  int p1 = s * v1 + t1 * 2;
  int p2 = s * v2 + t2 * 2;
  if (p1 == p2)
    return "Friendship";
  else if (p1 > p2)
    return "Second";
  else
    return "First";
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "R", stdout);
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  cout << winner(s, v1, v2, t1, t2) << endl;
  return 0;
}