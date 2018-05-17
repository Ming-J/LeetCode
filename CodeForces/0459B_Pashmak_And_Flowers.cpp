#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> flower(n,0);
  for(int i = 0; i < n; ++i){
    int t;
    cin>>t;
    flower[i] = t;
  }
  unordered_map<int,long long> count;
  int maxVal = INT_MIN;
  int minVal = INT_MAX;
  for(int beauty:flower){
    if(beauty < minVal) minVal = beauty;
    if(beauty > maxVal) maxVal = beauty;
    count[beauty]++;
  }
  unsigned long long int ways= (maxVal == minVal)?
    count[maxVal] * (count[maxVal] - 1) / 2
    :count[maxVal]*count[minVal];
  cout<<maxVal-minVal<<' '<<ways<<endl;
}
