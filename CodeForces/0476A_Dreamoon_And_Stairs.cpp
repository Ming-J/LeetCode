#include <iostream>
using namespace std;

int main(){
  int stairs;
  int multiple;
  cin>>stairs>>multiple;
  int minSteps = stairs/2 + stairs%2;
  for(int i = minSteps; i <= stairs; ++i){
    if(i%multiple == 0){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}
