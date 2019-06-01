#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source,
                        vector<int> &target) {
    for (auto b : blocked)
      _blocked.insert(to_string(b[0]) + '_' + to_string(b[1]));
    return bfs(source,target) || bfs(target,source);
  }

private:
  unordered_set<string> _blocked;
  vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int QRID_SIZE = 1000000;

  bool bfs(vector<int>& source, vector<int> &target) {
    unordered_set<string> visited;
    visited.insert(to_string(source[0]) + '_' + to_string(source[1]));
    queue<pair<int, int>> _q;
    _q.push({source[0],source[1]});
    while (!_q.empty()) {
      int r1 = _q.front().first, c1 = _q.front().second, r2 = target[0],
          c2 = target[1];
      if ((r1 == r2 && c1 == c2) || _blocked.empty() || visited.size() > 20000)
        return true;
      for (int i = 0, r = r1, c = c1; i < dir.size(); ++i) {
        int r3 = r + dir[i].first, c3 = c + dir[i].second;
        if (0 <= r3 && r3 < QRID_SIZE && 0 <= c3 && c3 < QRID_SIZE) {
          string pos2 = to_string(r3) + '_' + to_string(c3);
          auto findit = _blocked.find(pos2);
          if (findit == _blocked.end() && visited.find(pos2) == visited.end()) {
            //cout << pos2 << ' ' << _q.size() << endl;
            visited.insert(pos2);
            _q.push({r3, c3});
          }
        }
      }
      _q.pop();
    }
    return false;
  }
};

int main() {
  int r = 1, c = 3;
  vector<vector<int>> blocked = {
      {691938, 300406}, {710196, 624190}, {858790, 609485},
      {268029, 225806}, {200010, 188664}, {132599, 612099},
      {329444, 633495}, {196657, 757958}, {628509, 883388}};
  vector<int> source = {655988, 180910};
  vector<int> target = {267728, 840949};
  Solution s;
  if (s.isEscapePossible(blocked, source, target))
    cout << "true" << endl;
  else
    cout << "false" << endl;
}
