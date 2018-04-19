#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
			  int src, int dst, int K) {
      unordered_map<int, vector<pair<int,int> > > info;
      insertFlight(info,flights);
      vector< vector<int> > bellman(K+2,vector<int>(n,INT_MAX));
      bellman[0][src] = 0;
      for(size_t i = 0; i < bellman[0].size();++i){
	//if(i != src) bellman[i] = INT_MAX;
      }
      for(size_t i = 1; i < bellman.size(); ++i){
	for(size_t j = 0; j < bellman[i-1].size();++j){
	  bellman[i][j] = min(bellman[i-1][j],bellman[i][j]);
	  if(bellman[i-1][j] != INT_MAX){
	    int start = bellman[i-1][j];
	    cout<<"Start:"<<start<<' '<< j<<endl;
	    if(info.find(j) != info.end()){
	      for(auto fly : info[j]){
		cout<<j<<' '<<fly.first<<' '<<fly.second<<endl;
		int to = fly.first;
		int newFare = fly.second;
		bellman[i][to] = min(bellman[i-1][to], bellman[i-1][j] +
				     newFare);
	      }
	    }
	  }
	}
      }
      for(auto i : bellman){
	for(auto j: i){
	  cout<<j<<' ';
	}
	cout<<endl;
      }
      
      return bellman[K+1][dst] == INT_MAX ? -1 : bellman[K+1][dst];
    }
private:
  void insertFlight(unordered_map<int,vector<pair<int,int> > >& info,
		    const vector<vector<int> > flights){
    for(const vector<int> v : flights){
      if(info.find(v[0]) == info.end()){
	info.insert({v[0],{{v[1],v[2]}}});
      }else{
	info[v[0]].push_back({v[1],v[2]});
      }
    }
  }
};

int main(){
  Solution test;
  int n = 3;
  vector<vector<int>> input = {{0,1,100},{1,2,100},{0,2,500}};
  int src = 0;
  int dst = 2;
  int k = 1;
  cout<<test.findCheapestPrice(n,input,src,dst,k)<<endl;
  return 0;
}
