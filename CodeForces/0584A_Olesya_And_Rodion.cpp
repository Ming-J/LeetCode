#include <iostream>
using namespace std;

int main(){
  int a, b;
  cin>>a>>b;
  if(a == 1 and b == 10){
    cout<<"-1"<<endl;
  }else{
    string str;
    if(b == 10){
      str = "1";
      str.insert(str.end(),a-1,'0');
    }else{
      str.assign(a,static_cast<char>(b+'0'));
    }
    cout<<str<<endl;
  }
}
