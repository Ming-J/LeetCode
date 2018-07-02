#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
  n packets
  ith have ai ballons

  dont rip the packets
  distribute all packets
  
*/
int main(){
  int n;
  cin>>n;
  vector<int> packets(n);
  for(auto& p : packets){
    cin>>p;
  }
  if(n < 2 || (n == 2 && packets.front() == packets.back())){
    cout<<-1<<endl;
    return 0;
  }
  vector<int> ps(n);
  partial_sum(packets.begin(),packets.end(),ps.begin());
  for(int i = 0; i < ps.size() - 1; ++i){
    if(ps[i] != ps.back()-ps[i]){
      cout<<i+1<<endl;
      for(int j = 1; j <= i+1; ++j){
	cout<<j<<' ';
      }
      return 0;
    }
  }
  cout<<-1<<endl;
}
