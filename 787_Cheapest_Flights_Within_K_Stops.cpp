#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
			  int src, int dst, int K) {
      unordered_map<int, vector<pair<int,int> > > info;
      insertFlight(info,flights);
      vector< vector<int> > bellman(K+1,vector<int>(0,n));
      for(size_t i = 0; i < bellman[0].size();++i){
	if(i != src)
      }
      return minPrice == INT_MAX ? -1 : minPrice;
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
