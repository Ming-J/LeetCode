#include <iostream>
using std::cin;
using std::cout;

int heavie(int limak, int bob){
  int year = 0;
  do{
    ++year;
    limak *= 3;
    bob *= 2;
  }while(limak <= bob);
  return year;
}

int main(){
  int limak, bob;
  cin>>limak>>bob;
  cout<<heavie(limak,bob);
}
