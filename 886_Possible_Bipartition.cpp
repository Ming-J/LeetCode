#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    graph = vector<vector<int>>(N);
    for(auto& pa : dislikes){
      graph[pa[0]-1].push_back(pa[1]-1);
      graph[pa[1]-1].push_back(pa[0]-1);
    }
    colors.assign(N,0); //0 uncoloe, 1 red, -1 blue
    for(int i = 0; i < N; ++i){
      if(colors[i] == 0 && !dfs(i,1)) return false;
    }
    return true;
  }

  bool dfs(int current, int color){
    colors[current] = color;
    for(int next : graph[current]){
      //checking if the next node is same color as current
      if(colors[next] == color) return false;
      //Checking to see if coloring the next node is successful
      if(colors[next] == 0 && !dfs(next,color*-1)) return false;
    }
    return true;
  }

private:
  vector<int> colors;
  vector<vector<int>> graph;
};

int main(){
  Solution te;
  vector<vector<int> > dislike = {{1,2},{2,3}};
  if(te.possibleBipartition(3,dislike)) cout<<"True"<<endl;
  else cout<<"False"<<endl;
}
