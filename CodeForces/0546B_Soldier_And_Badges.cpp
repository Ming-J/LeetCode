#include <iostream>
#include <unordered_set>
using namespace std;


int main(){
  int n;
  cin>>n;
  int t;
  unordered_set<int> s;
  int coins = 0;
  for(int i = 0; i < n; ++i){
    cin>>t;
    while(s.find(t)!=s.end()){
      ++coins;
      ++t;
    }
    s.insert(t);
  }
  cout<<coins<<endl;
}
