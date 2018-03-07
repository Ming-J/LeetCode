#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int balance = 0;
    int start = 0;
    for(size_t i = 0; i < gas.size(); ++i){
      balance += gas[i] - cost[i];
      if(balance < 0 ){
	start = i+1;
	balance = 0;
      }
    }
    return (balance<0) -1 : start;
  }
};
