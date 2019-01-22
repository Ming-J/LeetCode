#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int minAreaRect(vector<vector<int>> &points) {
    unordered_set<string> points_set;
    for (auto &p : points)
      points_set.insert(PointToString(p));
    int area = numeric_limits<int>::max();
    for (size_t i = 0; i < points.size() - 2; ++i) {
      for (size_t j = i + 1; j < points.size(); ++j) {
        if (points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
          vector<int> p1 = {points[i][0], points[j][1]};
          vector<int> p2 = {points[j][0], points[i][1]};
          if (points_set.find(PointToString(p1)) != points_set.end() &&
              points_set.find(PointToString(p2)) != points_set.end()) {
            area = min(area, abs(points[i][0] - points[j][0]) *
                                 abs(points[i][1] - points[j][1]));
          }
        }
      }
    }
    return (area == numeric_limits<int>::max()) ? 0 : area;
  }

private:
  string PointToString(vector<int> &point) {
    return to_string(point[0]) + "_" + to_string(point[1]);
  }

  int getArea(vector<int> p1, vector<int> p2, vector<int> p3, vector<int> p4) {
    pair<int, int> pp1 = {p1[0], p1[1]};
    pair<int, int> pp2 = {p2[0], p2[1]};
    pair<int, int> pp3 = {p3[0], p3[1]};
    pair<int, int> pp4 = {p4[0], p4[1]};
    vector<pair<int, int>> pairs = {pp1, pp2, pp3, pp4};
    sort(pairs.begin(), pairs.end());
    if (pairs[0].first != pairs[1].first ||
        pairs[0].second != pairs[2].second ||
        pairs[1].second != pairs[3].second ||
        pairs[2].first != pairs[3].first) {
      return numeric_limits<int>::max();
    }
    return abs(pairs[3].first - pairs[0].first) *
           abs(pairs[3].second - pairs[0].second);
  }
};

int main() {

  Solution t;
  vector<vector<int>> input = {{1, 1}, {1, 3}, {3, 1}, {3, 3}, {4, 1}, {4, 3}};
  cout << t.minAreaRect(input) << endl;
}
