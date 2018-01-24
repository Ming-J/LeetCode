#include <iostream>
using namespace std;

int main(){
  int price = 0;
  int burles = 0;
  cin>>price>>burles;
  int shovel = 1;
  int total = price;
  while( total%10!=0 && total%10 != burles){
    total += price;
    shovel++;
  }
  cout<<shovel;
};
