#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findCircleNum(vector<vector<int>>& M) {
    int cnt = 0;
    for(size_t i = 0; i < M.size(); ++i){
      for(size_t j = 0; j < M[i].size(); ++j){
	if(M[i][j] == 1 && i == j){
	  ++cnt;
	  M[j][i] == 0;
	}
      }
    }
  }
};
