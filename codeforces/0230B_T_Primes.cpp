#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

void getPrimes(vector<int>& array, unordered_set<uint64_t>& tPrime){
  uint64_t limit = 1000000;
  array.assign(limit,0);
  for(uint64_t i = 2; i < array.size(); ++i){
    if(array[i] == 0){
      tPrime.emplace(i*i);
      uint64_t j = i;
      while(j < array.size()){
	array[j] = 1;
	j += i;
      }
    }
  }
}

int main(){
  vector<int> array;
  unordered_set<uint64_t> tPrime;
  getPrimes(array,tPrime);
  int n;
  cin>>n;
  for(int i =0; i < n; ++i){
    uint64_t j;
    cin>>j;
    if(tPrime.find(j) == tPrime.end()){
      cout<<"NO"<<endl;
    }else{
      cout<<"YES"<<endl;
    }
  }
}
