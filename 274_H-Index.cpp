#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
  3 0 6 1 5
  0 1 3 5 6
 `3 5 6 

  0 1
2  1  0

 100
1    0

 0 0 1
3 2 1 0

0 
1 1 paper with 1 and more and 1 paper witn 1 and less
2
  
*/
class Solution{
public:
  //using a bucket sort as a hash map
  int hIndex(vector<int>& citations){
    int hash[citations.size()+1] = {};
    for(auto cur: citations){
      if(cur<=citations.size()){
	++hash[cur];
      }else{
	++hash[citations.size()];
      }
    }
    int sum = 0;
    for(size_t i = citations.size(); i <= citations.size(); --i){
      cout<<i<<hash[i]<<endl;
      sum += hash[i];
      if(sum >= i){
	return i;
      }
    }
    return 0;
  }
  //time: O(nlogn) using sorting
  //space: O(1)
  int hIndexSort(vector<int>& citations){
    sort(citations.begin(),citations.end());
    int hind = citations.size();
    for(size_t i = 0; i < citations.size(); ++i){
      int hi = hind;
      int cur = citations[i];
      if( cur>=hi ){
	return hind;
      }
      --hind;
    }
    return 0;
  }
 
};

int main(){
  vector<int> input = {0,0,1};
  Solution test;
  cout<<test.hIndex(input)<<endl;
}
