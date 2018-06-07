#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode{
  int label;
  vector<UndirectedGraphNode*> neighbors;
  UndirectedGraphNode(int x) : label(x) {}
};

class Solution{
public:
  UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node){
    if(node==NULL) return node;
    UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
    visited.insert(make_pair(node,newNode));
    queue<UndirectedGraphNode*> q;
    q.push(node);
    while(!q.empty()){
      UndirectedGraphNode* cur = q.front();
      q.pop();
      for(auto nextNode: cur->neighbors){
	if(visited.find(nextNode) == visited.end()){
	  UndirectedGraphNode* newNeighbor = new UndirectedGraphNode(nextNode->label);
	  q.push(nextNode);
	  visited.insert(make_pair(nextNode,newNeighbor));
	}
	UndirectedGraphNode* copyCur = visited[cur];
	copyCur->neighbors.push_back(visited[nextNode]);
      }  
    }
    return newNode;
  }
};
