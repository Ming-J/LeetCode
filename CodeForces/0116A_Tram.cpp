#include <iostream>
using namespace std;

int main(){
  int n, exit, enter;
  int capacity = 0;
  int maxCap = 0;
  cin>>n;
  for( int i = 0; i < n; i++ ){
    cin>>exit>>enter;
    capacity -= exit;
    capacity += enter;
    maxCap = max( maxCap, capacity );
  }
  cout<<maxCap;
}
