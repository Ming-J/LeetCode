#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector< vector<int> > ans;
    for(int i : graph[0]){
      vector<int> path = {0,i};
      queue<vector<int> > q;
      q.push(path);
      while(!q.empty()){
	size_t depth = q.size();
	for(size_t j = 0; j < depth; ++j){
	  vector<int> cur = q.front();
	  q.pop();
	  if(cur.back() != graph.size() -1 ){
	    for( auto node : graph[cur.back()]){
	      vector<int> adding = cur;
	      adding.push_back(node);
	      q.push(adding);
	    }
	  }else{
	    ans.push_back(cur);
	  }
	}
      }
    }
    return ans;
  }
};
