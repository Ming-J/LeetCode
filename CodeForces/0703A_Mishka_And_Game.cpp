#include <iostream>
using namespace std;

int main(){
  int mishka=0, chris=0;
  int n;
  cin>>n;
  for(int i = 0; i < n; ++i){
    int m, c;
    cin>>m>>c;
    if(m!=c){
      if(c>m){
	++chris;
      }else{
	++mishka;
      }
    }
  }
  if(mishka == chris) cout<<"Friendship is magic!^^";
  if(mishka > chris) cout<<"Mishka";
  if(mishka < chris) cout<<"Chris";
}
