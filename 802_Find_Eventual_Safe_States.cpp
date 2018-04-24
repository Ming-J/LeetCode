#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> ans;
    vector<State> nodeState(graph.size(),UNKNOWN);
    for(size_t i = 0; i < graph.size(); ++i){
      if(dfs(nodeState,graph,i) == SAFE){
	ans.push_back(i);
      }
    }
    return ans;
  }

private:
  enum State {UNKNOWN, VISITING, SAFE, UNSAFE};
  State dfs(vector<State>& states, const vector<vector<int> >&g,
	    int cur){
    //if we enter a node that is visiting, then there is a cycle
    if(states[cur] == VISITING){
       return UNSAFE;
    }
    if(states[cur] != UNKNOWN){
      return states[cur];
    }
    states[cur] = VISITING;
    for(int dst : g[cur]){
      //Checking all the childrens are unsafe
      if(dfs(states,g,dst) == UNSAFE){
	return states[cur] = UNSAFE;
      }
    }
    return states[cur] = SAFE;
  }
};
