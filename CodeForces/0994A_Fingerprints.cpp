#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
  int s, f;
  cin>>s>>f;
  vector<int> seq(s);
  for(auto& i : seq) cin>>i;
  unordered_set<int> fin(f);
  for(int i = 0; i < f; ++i){
    int t;
    cin>>t;
    fin.insert(t);
  }

  for(size_t i = 0; i < seq.size(); ++i){
    if(fin.find(seq[i])!=fin.end()) cout<<seq[i]<<' ';
  }
}
