#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int n;
  cin>>n;
  string n1, n2;
  cin>>n1>>n2;
  int moves = 0;
  for(int i = 0; i < n ;++i){
    int diff = abs(n1[i] - n2[i]);
    moves += (10-diff < diff)? 10 - diff : diff;
  }
  cout<<moves<<endl;
}
