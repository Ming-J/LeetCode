#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minSwapsCouples(vector<int>& row) {
    vector<int> pos(row.size());
    for(size_t i = 0; i < row.size(); ++i){
      pos[row[i]] = i;
    }
    int count = 0;
    for(size_t i = 0; i < row.size(); i+=2){
      if(row[i]/2 != row[i+1]/2){
	++count;
	int i1 = i+1;
	int i2;
	if(row[i]%2 == 0){
	  i2 = pos[row[i]+1];
	}else{
	  i2 = pos[row[i]-1];
	}
	pos[row[]]
	swap(row[i1],row[i2]);
	pos[row[i2]] = i2;
	pos[row[i1]] = i1;
      }
    }
    return count;
  }
};
