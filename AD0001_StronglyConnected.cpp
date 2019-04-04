#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num(vector<vector<int>>& vc,int i, int j, vector<vector<bool>>& visited){
  if(0<=i && i < vc.size() && 0 <= j && j < vc.front().size() && !visited[i][j] && vc[i][j] == 1){
    visited[i][j] = true;
    return 1 +
      num(vc,i+1,j,visited)+
      num(vc,i-1,j,visited)+
      num(vc,i,j+1,visited)+
      num(vc,i,j-1,visited);
  }
  return 0;
}

int getComp(vector<vector<int>>& vc){
  vector<vector<bool>> visited(vc.size(),vector<bool>(vc.front().size(),false));
  int count = 0;
  for(size_t i = 0; i < vc.size(); ++i){
    for(size_t j = 0; j < vc.front().size();++j){
      if(!visited[i][j]){
	count = max(count, num(vc,i,j,visited));
      }
    }
  }
  return count;
}


int main(){
  vector<vector<int>> input =
    {
     {1,1,0,0,0},
     {0,1,1,0,0},
     {0,1,0,1,0},
     {1,0,0,0,0},
    };
  cout<<"Hello"<<' '<<getComp(input)<<endl;
}
