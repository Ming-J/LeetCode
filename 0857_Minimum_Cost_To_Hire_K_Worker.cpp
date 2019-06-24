#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K) {
    // Sort them by their ratio
    vector<pair<int, int>> ratio;
    for (size_t i = 0; i < quality.size(); ++i) {
      ratio.push_back(make_pair(wage[i], quality[i]));
    }
    auto cmp = [](pair<int, int> &le, pair<int, int> &ri) {
      return le.first * 1.0 / le.second < ri.first * 1.0 / ri.second;
    };
    sort(ratio.begin(), ratio.end(), cmp);
    // Use priority queue to make a sliding window
    // We want K worker in the queue, when we encounter newer one
    // we remove the highest qualities(most expensive), and change the ratio
    auto func = [](pair<int, int> &le, pair<int, int> &ri) {
      return le.second < ri.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(func)> pq(
        func);
    int qualities = 0;
    double rate = 0;
    double price = numeric_limits<int>::max();
    for (pair<int, int> cur : ratio) {
      if (pq.size() < K) {
        pq.push(cur);
      } else {
        auto t = pq.top();
        pq.pop();
        qualities -= t.second;
        pq.push(cur);
      }
      qualities += cur.second;
      rate = max(rate, cur.first * 1.0 / cur.second);
      if (pq.size() == K)
        price = min(price, rate * qualities);
    }
    return price;
  }
};

int main() {
  vector<int> q = {3, 1, 10, 10, 1};
  vector<int> w = {4, 8, 2, 2, 7};
  Solution s;
  q = {10, 20, 5};
  w = {70, 50, 30};
  cout << s.mincostToHireWorkers(q, w, 2) << endl;
}
