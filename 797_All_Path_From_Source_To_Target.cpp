#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  //DFS Version
  vector< vector<int> > allPathsSourceTargetdfs(vector<vector<int> > & graph){
    vector< vector<int> > ans;
    vector<int> path={0};
    dfs(graph,path,ans);
    return ans;
  }
  void dfs(vector<vector<int> >& graph,vector<int> &path,
	   vector<vector<int> >& ans){
    if(path.back()==graph.size() - 1){
      ans.push_back(path);
    }else{
      int val = path.back();
      for(auto nodes: graph[val]){	
	path.push_back(nodes);
	dfs(graph,path,ans);
	path.pop_back();
      }
    }
  }
  //BFS
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
