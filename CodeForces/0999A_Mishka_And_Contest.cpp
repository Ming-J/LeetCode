#include <iostream>
#include <queue>
using namespace std;
/*
  n Problems = K
*/
int main(){
  int n, k;
  cin>>n>>k;
  deque<int> q;
  for(int i = 0; i < n; ++i){
    int t;
    cin>>t;
    q.push_back(t);
  }
  int count = 0;
  while(!q.empty()&&(q.front()<=k||q.back()<=k)){
    if(q.front()<=k){
      q.pop_front();
    }else{
      q.pop_back();
    }
    ++count;
  }
  cout<<count<<endl;
}
