#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Skating{
public:
  Skating(int n){
    x.assign(n,0);
    y.assign(n,0);
    visited.assign(n,false);
  }

  void insert(int i, int x_c, int y_c){
    x[i] = x_c;
    y[i] = y_c;
  }

  int findNewPoint(){
    int newPoint = 0;
    for(size_t i = 0; i < x.size(); ++i){
      if(!visited[i]){
	dfs(i);
	++newPoint;
      }
    }
    return newPoint-1;
  }

  void dfs(size_t cur){
    visited[cur] = true;
    for(size_t i = 0; i < x.size(); ++i){
      if(!visited[i]&&(x[i]==x[cur]||y[i]==y[cur])){
	dfs(i);
      }
    }
  }
  
private:
  vector<int> x;
  vector<int> y;
  vector<bool> visited;
};



int main(){
  int n;
  cin>>n;
  Skating s(n);
  for(int i = 0; i < n; ++i){
    int x,y;
    cin>>x>>y;
    s.insert(i,x,y);
  }
  cout<<s.findNewPoint()<<endl;
}
