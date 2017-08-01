/**********************************

Implement a Binary Search Algorithm

************************************/
#include <iostream>
#include <cmath>
using namespace std;

class Solution{
public:
  int arrangeCoins(int n){
    long con=n;
    int up=sqrt(1+8*con)-1;
    int down=up/2;
    return down;
  }
};

int main(){
  Solution test;
  cout<<test.arrangeCoins(1804289383)<<endl;
  cout<<test.arrangeCoins(8)<<endl;
  cout<<test.arrangeCoins(28)<<endl;
}
