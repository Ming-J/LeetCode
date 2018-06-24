#include <iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int twentyFive = 0;
  int fifty = 0;
  int hundred = 0;
  for(int i = 0; i < n; ++i){
    int t = 0;
    cin>>t;
    if(t == 25){
      twentyFive += 1;
    }else if(t == 50){
      twentyFive -= 1;
      fifty += 1;
    }else{
      if(fifty>0&&twentyFive>0){
	fifty -= 1;
	twentyFive -= 1;
      }else twentyFive -= 3;
    }
    if(twentyFive < 0 || fifty < 0){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}
