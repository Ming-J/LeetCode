#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
  int n;
  cin>>n;
  unordered_map<int,int> towers;
  int maxHeight = 0;
  for(int i = 0; i < n; ++i){
    int t;
    cin>>t;
    maxHeight= max(maxHeight,++towers[t]);
  }
  cout<<maxHeight<<towers.size()<<endl;
}
