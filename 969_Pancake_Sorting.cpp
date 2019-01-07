#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
  vector<int> pancakeSort(vector<int>& A) {
    vector<int> indexs;
    for(size_t i = A.size() - 1; i < A.size() ; --i){
      size_t largest_val = A[0];
      size_t largest_ind = 0;
      for(size_t x = 0; x <= i; ++x){
	if(largest_val < A[x]){
	  largest_val = A[x];
	  largest_ind = x;
	}
      }
      cout<<largest_val<<' '<<largest_ind<<endl;
      reverse(A.begin(), A.begin() + largest_ind + 1);
      indexs.push_back(largest_ind + 1);
      reverse(A.begin(), A.begin() + i + 1);
      indexs.push_back(i+1);
    }
    return indexs;
  }
};


int main(){
  vector<int> input = { 3 , 2, 4, 1};
  Solution t;
  t.pancakeSort(input);
  for(auto i : input) cout<<i<<' ';
}
