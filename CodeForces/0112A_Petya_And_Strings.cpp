#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  string a = "abcdefgxd";
  string b = "AbCdEfFuv";
  cin>>a;
  cin>>b;
  transform(a.begin(),a.end(),a.begin(),::toupper);
  transform(b.begin(),b.end(),b.begin(),::toupper);
  int res = a.compare(b);
  if(res > 0){
    res = 1;
  }
  if(res < 0){
    res = -1;
  }
  cout<<res<<endl;
}
