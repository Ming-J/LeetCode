#include <iostream>
using namespace std;

class Solution {
public:
  int integerReplacement(int n) {
    return longInt(n);
  }
  int longInt(long n){
    if( n == 1 ){
      return 0;
    }
    if( n%2 == 0){
      return longInt(n/2) + 1;
    }else{
      return min(longInt(n+1),longInt(n-1)) + 1;
    }
  }
};

int main(){
  Solution test;
  cout<<test.integerReplacement(8)<<endl;
}
