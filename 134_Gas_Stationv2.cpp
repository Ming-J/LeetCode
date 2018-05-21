#include <iostream>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0;
    int start = -1;
    int gasT = 0;
    int costT = 0;
    for(size_t i = 0, sum = 0; i < gas.size(); ++i){
      gasT += gas[i];
      costT += cost[i];
      total += gas[i] - cost[i];
      if(costT > gasT){
	gasT = 0;
	costT = 0;
	start = i;
      }
    }
    return total >= 0 ? start+1 : -1;
  }
};
