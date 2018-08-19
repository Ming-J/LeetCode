#include <iostream>
using namespace std;
/*
  
*/
int main(){
  int a, b, steps;
  cin>>a>>b>>steps;
  int shortest = abs(a)+abs(b);
  if(shortest <= steps && (shortest % 2 == steps % 2)){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
