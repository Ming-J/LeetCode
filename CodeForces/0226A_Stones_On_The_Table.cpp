#include <iostream>
using namespace std;

int main(){
  int n;
  string stones;
  cin>>n;
  cin>>stones;

  int i = 0;
  int count = 0;
  while( i < stones.size() ){
    int j=1;
    while(i + j < stones.size() && stones[i] == stones[i+j]){
      j++;
      count++;
    }
    i += j;
  }
  cout<<count;
}
