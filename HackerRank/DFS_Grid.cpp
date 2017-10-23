#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

void dfs(vector < vector<int> > &grid,vector <vector<bool> > &visited,  int i, int j, int& count){
  if(i<0||j<0||i>=grid.size()||j>=grid[0].size()){
    return; 
  }
  if(visited[i][j]==true){
    return;
  }
  visited[i][j]=true;
  if(grid[i][j]==1){
    count++;
    dfs(grid,visited,i-1,j-1,count);
    dfs(grid,visited,i-1,j,count);
    dfs(grid,visited,i-1,j+1,count);
    dfs(grid,visited,i,j-1,count);
    dfs(grid,visited,i,j+1,count);
    dfs(grid,visited,i+1,j-1,count);
    dfs(grid,visited,i+1,j,count);
    dfs(grid,visited,i+1,j+1,count);
  }else{
    return;
  }
}

int get_biggest_region(vector< vector<int> > grid) {
  int length=grid.size();
  int width=grid[0].size();
  vector< vector<bool> > visit;
  for(int i=0;i<length;i++){
    vector<bool> row;
    for(int j=0;j<width;j++){
      row.push_back(false);
    }
    visit.push_back(row);
  }
  int maxregion=INT_MIN;
  for(int i=0;i<length;i++){
    for(int j=0;j<width;j++){
      int connect=0;
      dfs(grid,visit,i,j,connect);
      maxregion=max(maxregion,connect);
    }
  }
  return maxregion;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}
