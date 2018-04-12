#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph {
  vector<int> arrnode;
  unordered_multimap<int, int> connection;
    public:
        Graph(int n) {
	  vector<int> temp(n,0);
	  arrnode=temp;
        }
    
        void add_edge(int u, int v) {
	  connection.insert(make_pair(u,v));
	  connection.insert(make_pair(v,u));
        }
    
        vector<int> shortest_reach(int start) {
	  vector<bool> visited(arrnode.size(),false);
	  queue<int> node;
	  queue<int> nextlvnode;
	  node.push(start);
	  int level=1;
	  int n=node.size();
	  while(!node.empty()){
	    int current=node.front();
	    node.pop();
	    n--;
	    visited[current]=true;
	    pair<unordered_multimap<int,int>::iterator,unordered_multimap<int,int>::iterator > range;
	    range=connection.equal_range(current);
	    for(unordered_multimap<int,int>::iterator it=range.first;it!=range.second;++it){
	      if(visited[it->second]==false){
		node.push(it->second);
		arrnode[it->second]++;
	      }
	    }
	  }
	  for(int i=0;i<arrnode.size();i++){
	    arrnode[i]*=6;
	    if(arrnode[i]==0){
	      arrnode[i]=-1;
	    }
	  }
	  return arrnode;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
