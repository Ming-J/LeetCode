#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

class Solution{
public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<int> shortestDistance(N,INT_MAX);
    shortestDistance[K-1] = 0;
    unordered_map<int, vector<pair<int,int> > > direction;
    for( vector<int> ti : times){
      if(direction.find(ti[0]) == direction.end()){
	direction[ti[0]] = {make_pair(ti[1], ti[2])};
      }else{
	direction[ti[0]].push_back({ti[1],ti[2]});
      }
    }
    auto comp = [](pair<int,int> lhs, pair<int,int> rhs)
      { return lhs.first > rhs.first;};
    priority_queue<,
      vector<pair<int,int> > > pq;
    

    
    
    for( int d: shortestDistance){
      cout<<d<<' ';
    }
    cout<<endl;
    return 0;
  }
};


int main(){
  int N = 4;
  int K = 2;
  vector< vector<int> > times = {{2,1,1},{2,3,1},{3,4,1}};
  Solution test;
  cout<<test.networkDelayTime(times,N,K);
}
