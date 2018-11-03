#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
  vector<int> shortestToChar(string S, char C) {
    vector<int> arr(S.size(),numeric_limits<int>::max());
    for(size_t i = 0; i < S.size(); ++i){
      if(S[i]==C){
	arr[i] = 0;
	for(int j = i+1, dist = 1; j < S.size()&& S[j] != C;++j,++dist){
	  arr[j] = min(arr[j],dist);
	}
      }	
    }
    //    for(auto i : arr) cout<<i<<' ';
    for(size_t i = S.size() - 1; i < S.size(); --i){
      if(S[i]==C){
	arr[i] = 0;
	for(int j = i-1, dist = 1; j >= 0&& S[j] != C;--j,++dist){
	  arr[j] = min(arr[j],dist);
	}
      }
    }
    return arr;
  }
};


int main(){
  Solution s;
  auto a = s.shortestToChar("loveleetcode",'e');
  for(auto i : a) cout<<i<<' ';
}
