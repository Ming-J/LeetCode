#include <iostream>
using namespace std;
/*
  234
*/

int main(){
  int odd, even;
  cin>>odd>>even;
  if(abs(odd-even)<2&&(odd != 0 || even != 0)){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
