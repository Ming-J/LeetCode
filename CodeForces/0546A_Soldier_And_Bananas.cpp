#include <iostream>
using namespace std;

int main(){
  int bananaCost, wallet, bananaWanted;
  cin >> bananaCost >> wallet >> bananaWanted;
  int sum = 0;
  for( int i = 1; i <= bananaWanted; i++){
    sum += bananaCost * i;
  }
  sum = sum - wallet;
  sum = (sum > 0) ? sum : 0;
  cout<<sum<<endl;
}
