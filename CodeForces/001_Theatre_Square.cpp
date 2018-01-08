#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  unsigned long long int n,m,a;
  cin>>n>>m>>a;
  //scanf("%llu %llu %llu",&n,&m,&a);
  n=(n%a!=0)?(n/a+1):(n/a);
  m=(m%a)?(m/a+1):(m/a);
  cout<<n*m<<endl;
  //printf("%llu",n*m);
  return 0;
}
