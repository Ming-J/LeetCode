#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
  vector<int> storage;
public:
  int climbStairs(int n){
    if(n==1){
      return 1;
    }
    if(n==2){
      return 2;
    }
    int ways;
    int dpone=1;
    int dptwo=2;
    for(int i=3;i<=n;i++){
      ways=dpone+dptwo;
      dptwo=dpone;
      dpone=ways;
    }
    //ways=climbStairs(n-1)+climbStairs(n-2);
    return ways;
  }
};
