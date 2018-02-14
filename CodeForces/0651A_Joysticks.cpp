#include <iostream>
using namespace std;

void checkMax(int &joy1, int &joy2){
  int n1 = joy1;
  int n2 = joy2;
  joy1 = max(n1,n2);
  joy2 = min(n1,n2);
}

int main(){
  int joy1, joy2;
  cin>>joy1>>joy2;
  int minutes = 0;
  while(joy1 > 0 && joy2 > 0){
    if(joy1 == 1 && joy2 == 1){
      cout<<minutes<<endl;
      return 0;
    }
    checkMax(joy1, joy2);
    joy2++;
    joy1 -= 2;
    minutes++;
  }
  cout<<minutes<<endl;
}
