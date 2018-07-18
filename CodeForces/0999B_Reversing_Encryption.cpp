#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin>>n;
  string str;
  cin>>str;
  for(int i = 1; i <= n; ++i){
    if(n%i==0){
      reverse(str.begin(),str.begin()+i);
    }
  }
  cout<<str<<endl;
}
