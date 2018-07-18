#include <iostream>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  int count = 0;
  for(int i = 0; i <= 1000; ++i){
    for(int j = 0; j <= 1000; ++j){
      bool n_t = (i*i + j) == n;
      bool m_t = (i + j * j) == m;
      if(n_t && m_t) ++count;
    }
  }
  cout<<count<<endl;
}
