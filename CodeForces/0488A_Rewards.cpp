#include <iostream>
using namespace std;

int main(){
  int shelf, c1,c2,c3, m1, m2, m3;
  cin>>c1>>c2>>c3;
  int ct = c1 + c2 + c3;
  cin>>m1>>m2>>m3;
  int mt = m1 + m2 + m3;
  cin>>shelf;
  for(int i = shelf; i > 0; --i){
    if(ct > 0){
      ct -= 5;
    }else{
      mt -= 10;
    }
  }
  if(ct <= 0 && mt <= 0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
