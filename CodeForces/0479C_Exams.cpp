#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<pair<int,int> > dates(n,{0,0});;
  for(size_t i = 0; i < n; ++i){
    int a,b;
    cin>>a>>b;
    dates[i]=make_pair(a,b);
  }
  sort(dates.begin(),dates.end());
  int mindate = 0;
  for(auto p: dates){
    if(min(p.first,p.second) >= mindate){
      mindate = min(p.first,p.second);
    }else{
      mindate = max(p.first,p.second);
    }
  }
  cout<<mindate<<endl;
}
