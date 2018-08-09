#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n, m;
  cin>>n>>m;
  vector<int> input(n);
  vector< vector<int> > remainder(m);
  for(size_t i = 0; i < input.size(); ++i){
    cin>>input[i];
    remainder[t%remainder.size()].push_back(i);
  }
  int count = 0;
  list<int> prev;
  int eq = n / m;
  auto calCount = [eq,&count,&prev,&input](vector<int> n){
    while(n.size() > eq){
      prev.push_back(n.back());
      n.pop_back();
    }
  };
  for_each(remainder.begin(),remainder.end(),calCount);
  cout<<count<<endl;
  for(auto i : input) cout<<i<<' ';
}
