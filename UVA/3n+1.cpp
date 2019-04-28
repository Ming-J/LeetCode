#include <iostream>
using namespace std;

int func(int N){
  int count = 1;
  while(N != 1){
    if(N % 2 == 1) N = 3*N +1;
    else N /= 2;
    count++;
  }
  return count;
}

int main(){
  int i, j;
  while(cin>>i>>j){
    int ma = 0;
    for(int lo = min(i,j); lo <= max(i,j); ++lo){
      ma = max(ma,func(lo));
    }
    cout<<i<<' '<<j<<' '<<ma<<endl;
  }
  
}
