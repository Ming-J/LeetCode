#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
/*
m + 1 solder 1 ~ m +1
0  ~ n -1 types of solider


jth bit of number xi equal to one army of the ith player has solider
of the jth type



*/

int main(){
  int n, m, k, friends;
  cin>>n>>m>>k;
  vector<bitset<20> > players;
  for(int i = 0; i <= m; ++i){
    int army;
    cin>>army;
    players.push_back(bitset<20> (army));
  }
  auto fedor = players.back();
  friends = 0;
  for(size_t i = 0; i < players.size() - 1; ++i){
    int diff = (fedor ^ players[i]).count();
    if(diff <= k) ++friends;
  }
  cout<<friends<<endl;
}
