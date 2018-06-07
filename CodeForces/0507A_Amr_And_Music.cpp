#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int instruments, days;
  cin>>instruments>>days;
  vector< pair<int,int> > insts;
  for(int i = 0; i < instruments; ++i){
    int n;
    cin>>n;
    insts.push_back(pair<int,int>(n,i+1));
  }
  sort(insts.begin(),insts.end());
  int learned = 0;
  for(size_t i = 0; i < instruments; ++i){
    if(days>=insts[i].first){
      days -= insts[i].first;
      ++learned;
    }
  }
  cout<<learned<<endl;
  for(int i = 0; i < learned; ++i){
    cout<<insts[i].second<<' ';
  }
}
