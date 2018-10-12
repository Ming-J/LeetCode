#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Score {
  int point;
  int round;
  Score() {
    point = 0;
    round = 0;
  }
  Score(int p, int r) : point(p), round(r) {}
  void add(int p, int r) {
    point += p;
    round = r;
  }
};

auto cmp = [](pair<string, Score> lhs, pair<string, Score> rhs) {
  if (lhs.second.point == rhs.second.point) {
    return lhs.second.round > rhs.second.round;
  }
  return lhs.second.point < rhs.second.point;
};

class Game {
public:
  void round(string n, int i, int p) {
    if (players.find(n) == players.end())
      players.insert({n, Score(p, i)});
    else
      players[n].add(p, i);
  }

  string findWinner(vector<pair<string, int>> records) {
    int maxScore =
        max_element(players.begin(), players.end(), cmp)->second.point;
    unordered_map<string, int> p;
    for (auto pa : records) {
      p[pa.first] += pa.second;
      if (p[pa.first] >= maxScore && players[pa.first].point == maxScore)
        return pa.first;
    }
    return "";
  }

private:
  unordered_map<string, Score> players;
};

int main() {
  int n = 0;
  cin >> n;
  Game current;
  vector<pair<string, int>> rounds;
  for (int i = 0; i < n; ++i) {
    string s;
    int p;
    cin >> s >> p;
    current.round(s, i, p);
    rounds.push_back({s, p});
  }
  cout << current.findWinner(rounds) << endl;
}
