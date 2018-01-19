#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin >> n;

  int sum =0;
  int pocket[n];
  for(int i = 0; i < n; i++){
    int c;
    cin >> c;
    sum += c;
    pocket[i] = c;
  }
  sort(pocket,pocket+n);
  int cN=0;
  int steal = 0;
  for( int i = n-1; i >= 0; i--){
    cN++;
    sum -= pocket[i];
    steal += pocket[i];
    if( sum < steal ){
      cout<<cN<<endl;
      return 0;
    }
  }
  
}
