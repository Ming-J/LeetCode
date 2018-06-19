#include <iostream>
using namespace std;

long long com(long long x){
  return (x*(x-1))/2;
}

int main(){
  long long n,m;
  cin>>n>>m;
  long x = n/m;
  long y = n%m;
  long long kmin;
  if(m==1){
    kmin = com(n);
  }else{
    kmin = y*com(x+1) + (m-y)*com(x);
  }
  long long kmax = com(n-m+1);
  cout<<kmin<<' '<<kmax<<endl;
}
