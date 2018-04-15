#include <iostream>
using namespace std;

int main(){
  int n;
  string str;
  cin>>n;
  cin>>str;
  int one = 0, zero = 0;
  for(int i = 0; i < str.size(); ++i){
    if(str[i]=='1'){
      ++one;
    }else{
      ++zero;
    }
  }
  cout<<abs(one-zero);
}
