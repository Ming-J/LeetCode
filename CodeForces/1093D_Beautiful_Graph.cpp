#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool cheeckbib(unordered_map<int, vector<int>> &graph, vector<int> &buckets,
               int source, int color, vector<int> &count) {
  buckets[source] = color;
  if (color == -1)
    ++count[0];
  else
    ++count[1];
  for (auto v : graph[source]) {
    if (buckets[v] == 0) {
      if (!cheeckbib(graph, buckets, v, color * -1, count))
        return false;
    } else {
      if (color == buckets[v])
        return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int N = int(3e5) + 999;
  int MOD = 998244353;
  vector<int> twos(N, 0);
  twos[0] = 1;
  for (int i = 1; i < N; ++i) {
    twos[i] = (2 * twos[i - 1]) % MOD;
  }
  int test;
  cin >> test;
  for (int i = 0; i < test; ++i) {
    int v, e;
    cin >> v >> e;
    unordered_map<int, vector<int>> graph;
    vector<int> bucket(v, 0);
    for (int j = 0; j < e; ++j) {
      int from, to;
      cin >> from >> to;
      from--, to--;
      graph[from].push_back(to);
      graph[to].push_back(from);
    }
    bool notBib = true;
    int ans = 1;
    for (int j = 0; j < v; ++j) {
      vector<int> count(2, 0);
      if (bucket[j] == 0) {
        if (!cheeckbib(graph, bucket, j, 1, count)) {
          notBib = false;
          cout << 0 << endl;
          break;
        } else {
          ans = (ans * 1LL * ((twos[count[0]] + twos[count[1]]) % MOD) % MOD);
        }
      }
    }
    if (notBib) {
      cout << ans << endl;
    }
  }
}