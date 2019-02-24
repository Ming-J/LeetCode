#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N) {
        unordered_map<string, int> _map;
        string cur = vToString(cells), next;
        while (N > 0) {
            next = nextday(cur);
            auto it = _map.find(next);
            if (it == _map.end()) {
                _map.insert(make_pair(next, N--));
            } else {
                int dif = N - it->second;
                N %= dif;
            }
            cur = next;
        }
        vector<int> ans;
        for (char c : cur)
            ans.push_back(c - '0');
        return ans;
    }

  private:
    string nextday(string &cells) {
        string next(cells.size(), '0');
        for (size_t i = 1; i < cells.size() - 1; ++i) {
            if (cells[i - 1] == cells[i + 1])
                next[i] = 1;
        }
        return next;
    }
    string vToString(vector<int> &cells) {
        string cells_str;
        for (int n : cells) {
            cells_str += to_string(n);
        }
        return cells_str;
    }
};