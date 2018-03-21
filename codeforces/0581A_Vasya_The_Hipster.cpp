#include <iostream>
using namespace std;

int fashion(int& b, int &a){
  int m = min(a,b);
  a -= m;
  b -= m;
  return m;
}

int socks(int& b, int &a){
  return max(b/2,a/2);
}

int main(){
  int a,b;
  cin>>a>>b;
  cout<<fashion(a,b)<<endl;
  cout<<socks(a,b)<<endl;
}
