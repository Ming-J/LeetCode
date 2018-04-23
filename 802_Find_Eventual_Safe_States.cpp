#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> ans;
    unordered_map<int, vector<int> > from;
    unordered_map<int, unordered_set<int> > safe;
    for(size_t i = 0; i < graph.size(); ++i){
      if(graph[i].empty()){
	unordered_set<int> ss;
	safe.insert(make_pair(i,ss));
      }else{
	for( int dst : graph[i]){
	  if(from.find(dst) == from.end()){
	    vector<int> nv;
	    from.insert(make_pair(dst,nv));
	  }else{
	    from[dst].push_back(i);
	  }
	}
      }
    }
    return ans;
  }
};
