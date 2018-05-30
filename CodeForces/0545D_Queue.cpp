#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
  1 1 2 3 8 13 21 34 55
*/
int main(){
  int n;
  cin>>n;
  vector<int> disappointTime(n,0);
  for(int& t: disappointTime) cin>>t;
  sort(disappointTime.begin(),disappointTime.end());
  int partialSum = 0;
  int count = 0;
  auto f = [&](int n){
    if(partialSum <= n){
      ++count;
      partialSum += n;
    }
  };
  for_each(disappointTime.begin(),disappointTime.end(),f);
  cout<<count<<endl;
}
