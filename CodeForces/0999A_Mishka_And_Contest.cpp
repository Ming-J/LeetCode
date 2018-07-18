#include <iostream>
#include <deque>
using namespace std;

int main(){
  int n, k;
  cin>>n>>k;
  deque<int> dq;
  for(int i = 0; i < n; ++i){
    int t;
    cin>>t;
    dp.push_back(t);
  }
  int sloved = 0;
  while(!dq.empty()&&dq.front() <= k){
    ++sloved;
    dp.pop_front();
  }
  while(!dq.empty()&&dq.back() <= k){
    ++sloved;
    dp.pop_front();
  }
  
}
