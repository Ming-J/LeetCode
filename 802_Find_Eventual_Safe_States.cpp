#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //0 - unvisited, 1- visiting, 2 - safe, 3 - unsafe
    vector<int> nodeState(graph.size(),0);
    return ans;
  }

private:
  void dfs(vector<int>& states, const vector<vector<int> >&g,
	   int cur){
    if(states[cur] == 1){
      states[cur] = 3;
    }

  }
};
