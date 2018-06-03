#include <iostream>
#include <vector>
using namespace std;

int main(){
  int twos, threes, fives, six;
  cin>>twos>>threes>>fives>>six;
  int sum = 0;
  int twoFiftySix = min(twos,min(fives,six));
  if(twoFiftySix > 0){
    sum += twoFiftySix * 256;
    twos -= twoFiftySix;
    fives -= twoFiftySix;
    six -= twoFiftySix;
  }
  int thirtyTwo = min(threes, twos);
  sum += (thirtyTwo*32);
  cout<<sum<<endl;
}
