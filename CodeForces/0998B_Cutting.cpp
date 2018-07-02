#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n, budget;
  cin>>n>>budget;
  vector<int> seq(n);
  int o = 0;
  vector<int> odd;
  int e = 0;
  vector<int> even;
  for(auto& i : seq){
    cin>>i;
    if(i % 2 == 0) ++e;
    else ++o;
    odd.push_back(o);
    even.push_back(e);
  }
  vector<int> cuts;
  for(int i = 0; i < seq.size(); ++i){
    if(odd[i] == even[i] && i != seq.size() - 1){
      cuts.push_back(abs(seq[i]-seq[i+1]));
    }
  }
  sort(cuts.begin(),cuts.end());
  int sum = 0;
  for(int i = 0; i < cuts.size(); ++i){
    if(sum+cuts[i] > budget){
      cout<<i<<endl;
      return 0;
    }
    sum += cuts[i];
  }
  cout<<cuts.size()<<endl;
}
