#include <iostream>
#include <cmath>
using namespace std;

bool checkPoly(int angle){
  return 360 % (180-angle) == 0 ? true : false;
}

int main(){
  int n;
  cin>>n;
  for(int i = 0; i < n; ++i){
    int angle;
    cin>>angle;
    if(checkPoly(angle)){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
}
