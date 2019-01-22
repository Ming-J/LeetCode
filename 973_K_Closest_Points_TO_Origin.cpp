#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        vector<vector<int>> clostest;
        multimap<int, vector<int>> dist;
        for (auto p : points) {
            int distance = distanceSquare(p, {0, 0});
            dist.insert(make_pair(distance, p));
        }
        for (pair<int, vector<int>> point : dist) {
            if (clostest.size() < K)
                clostest.push_back(point.second);
        }
        return clostest;
    }

  private:
    int distanceSquare(vector<int> &p1, vector<int> p2) {
        int deltaA = p1[0] - p2[0];
        int deltaB = p1[1] - p2[1];
        return deltaA * deltaA + deltaB * deltaB;
    }
};