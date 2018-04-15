#include <iostream>
#include <bitset>
using namespace std;

int main(){
  int n=536870911;
  bitset<64> b(n);
  cout<<b.count()<<endl;
  int ans = 0;
  while(n){
    if( (n&1) == 1) ++ans;
    n >>= 1;
  }
  cout<<ans<<endl;
}
