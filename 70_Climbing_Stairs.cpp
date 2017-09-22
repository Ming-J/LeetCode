#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
  vector<int> storage;
public:
  int climbStairs(int n){
    storage(n,0);
    if(n==1){
      return 1;
    }
    if(n==2){
      return 2;
    }
    int ways=0;
    ways=climbStairs(n-1)+climbStairs(n-2);
    return ways;
  }
};
