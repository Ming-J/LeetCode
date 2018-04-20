#include <iostream>
using namespace std;

int main(){
  int stairs = 3;
  int multiple = 5;
  int minSteps = stairs/2 + stairs%2;
  for(int i = minSteps; i <= stairs; ++i){
    if(i%multiple ==0){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}
