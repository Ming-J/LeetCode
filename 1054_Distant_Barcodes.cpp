#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int> &barcodes) {
    if (barcodes.size() <= 2)
      return barcodes;
    // n -> times
    unordered_map<int, int> occurance;
    for (int bc : barcodes)
      occurance[bc]++;
    // Times, value
    priority_queue<pair<int, int>> arrange;
    for (auto p : occurance) {
      arrange.push({p.second, p.first});
    }
    vector<int> ans;
    while (arrange.size() >= 2) {
      pair<int, int> first = arrange.top();
      arrange.pop();
      pair<int, int> second = arrange.top();
      arrange.pop();
      ans.push_back(first.second);
      ans.push_back(second.second);
      // cout<<first.second<<" "<<second.second<<endl;
      --first.first, --second.first;
      if (first.first != 0)
        arrange.push(first);
      if (second.first != 0)
        arrange.push(second);
    }
    if (!arrange.empty())
      ans.push_back(arrange.top().second);
    // cout<<endl;
    return ans;
  }
};
int main() {
  Solution t;
  vector<int> input = {1, 1, 1, 1, 2, 2, 3, 3};
  t.rearrangeBarcodes(input);
}
