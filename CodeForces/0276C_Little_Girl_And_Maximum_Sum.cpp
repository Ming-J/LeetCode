#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class SUM {
public:
  SUM(int n, vector<int> v) {
    called.assign(n, 0);
    origin = v;
  }

  void query(int a, int b) {
    --a;
    ++called[a];
    if (b < called.size())
      --called[b];
  }

  unsigned long long int cal() {
    partial_sum(called.begin(), called.end(), called.begin());
    unsigned long long int sum = 0;
    sort(origin.begin(), origin.end());
    sort(called.begin(), called.end());
    for (size_t i = 0; i < origin.size(); ++i) {
      sum += (origin[i] * called[i]);
    }
    return sum;
  }

private:
  vector<unsigned long long> called;
  vector<int> origin;
};

int main() {
  ios_base::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> input(n);
  for (auto &i : input)
    cin >> i;
  SUM temp(n, input);
  int a, b;
  for (int i = 0; i < q; ++i) {
    cin >> a >> b;
    temp.query(a, b);
  }
  cout << temp.cal() << endl;
}
