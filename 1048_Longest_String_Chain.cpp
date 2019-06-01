#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int longestStrChain(vector<string> &words) {
    momo = vector<int>(words.size(), -1);
    sort(words.begin(), words.end(),
         [](string &a, string &b) { return a.size() < b.size(); });
    //Making a graph of the preprocesser
    unordered_map<int, vector<int>> graph = getGraph(words);
    for (auto p : graph)
      for (int c : p.second)
        cout << words[p.first] << "->" << words[c] << endl;
    int length = 0;
    //Using dfs traversal with memo with 
    for (int i = 0; i < words.size(); ++i) {
      if (momo[i] == -1)
        momo[i] = dfs(graph, i);
      length = max(length, momo[i]);
    }
    return length;
  }

private:
  vector<int> momo;
  unordered_map<int, vector<int>> getGraph(vector<string> &word) {
    unordered_map<int, vector<int>> graph;
    for (size_t i = 0; i < word.size(); ++i) {
      for (size_t j = i + 1; j < word.size(); ++j) {
        if (check(word[i], word[j]))
          graph[i].push_back(j);
      }
    }
    return graph;
  }

  bool check(string &prev, string &cur) {
    for (auto i = 0, j = 0; i < prev.size(); ++j) {
      if (prev[i] == ' ' || prev[i] == cur[j])
        ++i;
      if (j - i == 2)
        return false;
    }
    return true;
  }

  int dfs(unordered_map<int, vector<int>> &graph, int current) {
    auto it = graph.find(current);
    if (it == graph.end())
      return 1;
    int maxLength = 0;
    for (int k : it->second) {
      if (momo[k] == -1)
        momo[k] = dfs(graph, k) + 1;
      maxLength = max(maxLength, momo[k]);
    }
    return maxLength;
  }
};

int main() {
  vector<string> ab = {"a", "b", "ba", "bca", "bda", "bdca", "bdcaa"};
  ab = {"ksqvsyq", "ks",       "kss",        "czvh",  "zczpzvdhx",
        "zczpzvh", "zczpzvhx", "zcpzvh",     "zczvh", "gr",
        "grukmj",  "ksqvsq",   "gruj",       "kssq",  "ksqsq",
        "grukkmj", "grukj",    "zczpzfvdhx", "gru"};
  ab = {"kxbvnw",     "uqjszp",     "pmukt",    "aai",       "aaicwm",
        "mhkzelhyek", "cjv",        "v",        "uqjjspzpp", "aaim",
        "uqjjszp",    "uqjjspzppd", "uqjjspzp", "aaicm",     "pukt",
        "pvmukt",     "dgdb",       "aaicwbm",  "mhkelhyek", "jv"};
  Solution s;
  cout << s.longestStrChain(ab) << endl;
}
