/*
  n knights   k from the statement
  p_i  power of the ith 
  c_i coins of the ith knight
*/
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

int main(){
  int knight , k;
  cin>>knight>>k;
  vector<int> power(knight);
  for(int& p:power) cin>>p;
  map<int,long> coin;
  for(size_t i = 0; i < knight; ++i){
    int c;
    cin>>c;
    coin.insert(make_pair(power[i],c));
  }
  unordered_map<int,unsigned long long int> res;
  multiset<long> window;
  unsigned long long int sum = 0;
  for(auto it = coin.begin(); it != coin.end(); ++it){
    if(window.size() < k){
      sum += it->second;
      window.insert(it->second);
      res[it->first] = sum;
    }else{
      res[it->first] = sum+it->second;
      if((it->second > *(window.begin()))&&k>0){
	sum -= *window.begin();
	window.erase(window.begin());
	window.insert(it->second);
	sum += it->second;
      }
    }
  }
  for(size_t i = 0; i < power.size(); ++i){
    cout<<res[power[i]]<<' ';
  }
}
