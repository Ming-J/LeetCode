#include <iostream>
using namespace std;

int main(){
  int n, coins = 0;
  while(cin>>n){
    coins += n;
  }
  int rtn = (coins != 0 && coins % 5 == 0) ? coins/5 : -1;
  cout<<rtn;
}
