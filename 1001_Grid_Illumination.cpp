#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> gridIllumination(int N, vector<vector<int>> &lamps,
                               vector<vector<int>> &queries) {
    vector<int> ans;
    unordered_map<int, int> row, col, dia, opp_dia;
    unordered_map<int, unordered_set<int>> loc;
    for (auto l : lamps) {
      int r = l[0], c = l[1];
      loc[r].insert(c);
      ++dia[r - c], ++opp_dia[r + c], ++row[r], ++col[c];
    }
    vector<pair<int, int>> off = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0},
                                  {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    for (auto qu : queries) {
      int r = qu[0], c = qu[1];
      bool light = row.find(r) != row.end() || col.find(c) != col.end() ||
                   dia.find(r - c) != dia.end() ||
                   opp_dia.find(r + c) != opp_dia.end();
      ans.push_back((light) ? 1 : 0);
      for (auto delta : off) {
        int dr = r + delta.first, dc = c + delta.second;
        bool exist = false;
        if (0 >= dr && dr < N && 0 >= dc && dc < N) {
          auto row_exist = loc.find(dr);
          if (row_exist != loc.end() &&
              row_exist->second.find(dc) != row_exist->second.end()) {
            row_exist->second.erase(dc);
            if (row_exist->second.empty())
              loc.erase(dr);
            if (row.find(dr) != row.end() && --row[dr] == 0)
              row.erase(dr);
            if (col.find(dc) != col.end() && --col[dc] == 0)
              col.erase(dc);
            if (dia.find(dr - dc) != dia.end() && --dia[dr - dc] == 0)
              row.erase(dr - dc);
            if (opp_dia.find(dr + dc) != opp_dia.end() &&
                --opp_dia[dr + dc] == 0)
              row.erase(dr + dc);
          }
        }
      }
    }
    return ans;
  }

private:
  void print(int N, unordered_map<int, int> row, unordered_map<int, int> col,
             unordered_map<int, int> dia) {

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (row.find(i) != row.end() || col.find(j) != col.end() ||
            dia.find(i - j) != dia.end()) {
          cout << 1;
        } else {
          cout << 0;
        }
      }
      cout << endl;
    }
    cout << endl;
  }
};

int main() {
  int n = 100;
  vector<vector<int>> lamp = {
      {7, 55},  {53, 61}, {2, 82},  {67, 85}, {81, 75}, {38, 91}, {68, 0},
      {60, 43}, {40, 19}, {12, 75}, {26, 2},  {24, 89}, {42, 81}, {60, 58},
      {77, 72}, {33, 24}, {19, 93}, {7, 16},  {58, 54}, {78, 57}, {97, 49},
      {65, 16}, {42, 75}, {90, 50}, {89, 34}, {76, 97}, {58, 23}, {62, 47},
      {94, 28}, {88, 65}, {3, 87},  {81, 10}, {12, 81}, {44, 81}, {54, 92},
      {90, 54}, {17, 54}, {27, 82}, {48, 15}, {8, 46},  {4, 99},  {15, 13},
      {90, 77}, {2, 87},  {18, 33}, {52, 90}, {4, 95},  {57, 61}, {31, 22},
      {32, 8},  {49, 26}, {24, 65}, {88, 55}, {88, 38}, {64, 76}, {94, 76},
      {59, 12}, {41, 46}, {80, 28}, {38, 36}, {65, 67}, {75, 37}, {56, 97},
      {83, 57}, {2, 4},   {44, 43}, {71, 90}, {62, 40}, {79, 94}, {81, 11},
      {96, 34}, {38, 11}, {22, 3},  {54, 96}, {78, 33}, {54, 54}, {79, 98},
      {1, 28},  {0, 32},  {37, 11}};
  vector<vector<int>> query = {
      {24, 84}, {95, 68}, {80, 35}, {31, 53}, {69, 45}, {85, 29}, {87, 25},
      {42, 47}, {7, 59},  {99, 3},  {31, 70}, {64, 62}, {44, 91}, {55, 25},
      {15, 52}, {95, 33}, {21, 29}, {61, 34}, {93, 34}, {79, 27}, {30, 86},
      {52, 0},  {18, 10}, {5, 1},   {40, 21}, {11, 48}, {55, 94}, {22, 42},
      {81, 0},  {39, 43}, {5, 25},  {43, 29}, {45, 47}, {83, 93}, {77, 70},
      {22, 63}, {30, 73}, {18, 48}, {39, 88}, {91, 47}};
  Solution t;
  t.gridIllumination(100, lamp, query);
  vector<vector<int>> v(3, vector<int>(3));
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].size(); ++j) {
      cout << i - j << ' ';
    }
    cout << endl;
  }
}