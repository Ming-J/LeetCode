#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    queue<pair<int, int>> seven, thirty;
    int cost = 0;
    for (int d : days) {
      while (!seven.empty() && d >= seven.front().first)
        seven.pop();
      while (!thirty.empty() && d >= thirty.front().first)
        thirty.pop();
      seven.push({d + 7, cost + costs[1]});
      thirty.push({d + 30, cost + costs[2]});
      cost = min(cost + costs[0],
                 min(seven.front().second, thirty.front().second));
    }
    return cost;
  }
};

int main() {
  vector<int> days = {4, 5, 9, 11, 14, 16, 17, 19, 21, 22, 24};
  vector<int> cost = {1, 4, 18};
  Solution t;
  cout << t.mincostTickets(days, cost) << endl;
}