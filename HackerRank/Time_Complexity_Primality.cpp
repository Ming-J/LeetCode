#include <iostream>
using namespace std;

string checkprime(int num){
  for(size_t i=2;i<sqrt(num);i++){
    if(num==1){
      return "Not prime";  //1 is not a prime
    }
    if(num%i==0){
      return "Not prime";
    }
  }
  return "Prime";
}
