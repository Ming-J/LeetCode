#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int needed;
  cin>>needed;
  if(needed == 0){
    cout<<0<<endl;
    return 0;
  }
  auto cmp = [](const int lhs, const int rhs){return lhs<rhs;};
  priority_queue< int, vector<int>, decltype(cmp)> pq(cmp);
  for(int i = 0; i < 12; ++i){
    int m;
    cin>>m;
    pq.push(m);
  }
  int ans = 0;
  while(needed > 0 && pq.size()){
    ++ans;
    needed -= pq.top();
    pq.pop();
  }
  ans = (needed <= 0)? ans: -1;
  cout<< ans <<endl;
}
