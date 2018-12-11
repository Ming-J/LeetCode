#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourse, vector<pair<int, int>> &prerequisites) {
    vector<vector<int>> pre(numCourse);
    for (auto &pa : prerequisites) {
      pre[pa.first].push_back(pa.second);
    }
    vector<int> visited(numCourse, false);
    for (int i = 0; i < numCourse; ++i) {
      unordered_set<int> current_visited;
      if (!dfs(visited,current_visited,i,pre))
        return false;
    }
    return true;
  }

  bool dfs(vector<int> &visited, unordered_set<int> &current_visited,
           int course, vector<vector<int>> &preq) {
    // If the current course have been visited in the current DFS, then it's a cycle.
    if (current_visited.find(course) != current_visited.end()) {
      return false;
    }
    // Current Course have been visited in the previous DFS. No cycle
    if (visited[course])
      return true;
    // Current course have no other prerequisited,
    if (preq[course].size() == 0)
      return true;
    visited[course] = true;
    current_visited.insert(course);
    // visited all the prerequisited of current course
    for (int &pre : preq[course]) {
      if (!dfs(visited, current_visited, pre, preq))
        return false;
    }
    return true;
  }
};


int main() {
  int a = 2;
  vector<pair<int, int>> preq = {{1, 0}};
  Solution test;
  if (test.canFinish(a, preq)) {
    cout << "Y";
  } else {
    cout << "N";
  }
}
