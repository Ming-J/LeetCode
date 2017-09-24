#include <iostream>
#include <cmath>
using namespace std;

class Solution{
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest){
    if(buckets==1){return 0;}
    int timeToTry=(minutesToTest/minutesToDie)+1;
    double piggy=log(bucket)/log(timeToTry);
    return ceil(piggy);
  }
};
