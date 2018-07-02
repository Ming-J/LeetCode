#include <iostream>
using namespace std;

int main(){
  int n, a, b;
  cin>>n>>a>>b;
  if((b+1)>(n-a)){
    cout<<n-a<<endl;
  }else{
    cout<<b+1<<endl;
  }
  return 0;
}
