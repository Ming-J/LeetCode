#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int checkTri(int a, int b, int c){
  return (a+b>c)&&(b+c>a)&&(a+c>b);
}

int main(){
  int n;
  cin>>n;
  vector<int> lines(n,0);
  for(int i = 0; i < n; ++i){
    int t;
    cin>>t;
    lines[i]=t;
  }
  sort(lines.begin(),lines.end());
  int a,b,c;
  for(size_t i = 0; i < lines.size() - 2; ++i){
    a=lines[i];
    b=lines[i+1];
    c=lines[i+2];
    if(checkTri(a,b,c)){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}
