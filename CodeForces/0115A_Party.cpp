#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int dfs(unordered_map<int,vector<int> >& manager, vector<int>& lookup,
	int employee){
  if(lookup[employee-1] != 0){
    return lookup[employee-1];
  }
  if(manager.find(employee) == manager.end()){
    lookup[employee-1] = 1;
    return 1;
  }
  int minLv = INT_MIN;
  for(int i : manager[employee]){
    minLv = max(minLv,dfs(manager,lookup,i));
  }
  lookup[employee-1] = minLv+1;
  return minLv+1;
}

void build(unordered_map<int, vector<int> >& table,int employee,
	   int manager){
  if(manager != -1){
    table[manager].push_back(employee);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x;
  cin>>x;
  unordered_map<int, vector<int> > table;
  for(int i = 0; i < x; ++i){
    int t;
    cin>>t;
    build(table,i+1,t);
  }
  vector<int> lookup(x,0);
  int group  = 0;
  for(int i = 0; i < x; ++i){
    group = max(group,dfs(table,lookup,i+1));
  }
  cout<<group<<endl;
}
