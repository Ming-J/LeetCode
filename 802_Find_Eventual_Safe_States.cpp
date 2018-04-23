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
    vector<int> ends;
    unordered_set<int> ansSet;
    unordered_map<int, vector<int> > from;
    unordered_map<int, unordered_set<int> > safe;
    for(size_t i = 0; i < graph.size(); ++i){
      if(graph[i].empty()){
	ends.push_back(i);
	ansSet.insert(i);
      }else{
	for( int dst : graph[i]){
	  if(from.find(dst) == from.end()){
	    vector<int> nv;
	    nv.push_back(i);
	    from.insert(make_pair(dst,nv));
	  }else{
	    from[dst].push_back(i);
	  }
	}
      }
    }
    for(size_t i = 0; i < ends.size(); ++i){
      queue<int> q;
      q.push(ends[i]);
      while(!q.empty()){
	int n = q.size();
	for(int i = 0; i < n; ++i){
	  int cur = q.front();
	  q.pop();
	  for(int origin : from[cur]){
	    if(ansSet.find(origin) == ansSet.end()){
	      q.push(origin);
	      ansSet.insert(origin);
	    }
	  }
	}
      }
    }
    for(int i : ansSet){
      ans.push_back(i);
    }
    return ans;
  }
};
