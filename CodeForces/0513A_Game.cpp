#include <iostream>
using namespace std;


int whoWin(int n1, int n2, int k1, int k2){
  while(n1>0&&n2>0){
    n1 -= min(k1,1);
    n2 -= min(k2,1);
  }
  if(n1 <= 0){
    return 2;
  }else{
    return 1;
  }
}
x
int main(){
  int n1, n2, k1, k2;
  cin>>n1>>n2>>k1>>k2;
  if(whoWin(n1,n2,k1,k2) == 1){
    cout<<"First"<<endl;
  }else{
    cout<<"Second"<<endl;
  }
}
