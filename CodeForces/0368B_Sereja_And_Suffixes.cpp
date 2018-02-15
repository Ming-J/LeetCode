#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void createSet(vector<long> &arr, unordered_set<long> &sets, vector<long> &dp){
  dp.resize(arr.size());
  int dpVal = 0;
  for(size_t i = arr.size()-1; i < arr.size(); i--){
    auto it = sets.find(arr[i]);
    if(it == sets.end()){
      sets.insert(arr[i]);
      dpVal++;
    }
    dp[i] = dpVal;
  }
}

int main(){
  vector<long> array, dp;
  unordered_set<long> set;
  int n, l;
  cin>>n>>l;
  for( size_t i = 0; i < n; i++){
    int val;
    cin>>val;
    array.push_back(val);
  }
  createSet(array,set,dp);
  for(size_t i = 0; i < l;i++){
    cin>>n;
    cout<<dp[n-1]<<endl;
  }
  return 0;
}
