#include <iostream>
using namespace std;

class Solution {
public:
  int integerReplacement(int n) {
    if( n == 1 ){
      return 0;
    }
    if( n < 1){
      return 1000;
    }
    if(n/2 == 0){
      return integerReplacement(n/2) + 1;
    }else{
      return min(integerReplacement(n+1),integerReplacement(n-1)) + 1;
    }
  }
};

int main(){
  Solution test;
  cout<<test.integerReplacement(8)<<endl;
}
