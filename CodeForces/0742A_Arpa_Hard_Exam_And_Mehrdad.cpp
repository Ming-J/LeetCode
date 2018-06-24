#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  if(n == 0){
    cout<<1<<endl;
    return 0;
  }
  int product; 
  switch(n%4){
  case 1:
    product = 8;
    break;
  case 2:
    product = 4 ;
    break;
  case 3:
    product = 2;
    break;
  case 0:
    product = 6;
    break;
  }
  cout<<product<<endl;
}
