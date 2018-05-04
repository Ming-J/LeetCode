#include <iostream>
using namespace std;

int main(){
  int n, c, w = 0,pt;
  cin>>n>>c;
  for(int i = 0; i < n; ++i){
    int t;
    cin>>t;
    if(i == 0){
      w = 1;
    }else{
      if(t-pt <= c){
	++w;
      }else{
	w = 1;
      }
    }
    pt = t;
  }
  cout<<w<<endl;
}
