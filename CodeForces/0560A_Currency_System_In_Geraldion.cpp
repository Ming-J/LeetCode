#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> v(n,0);
  for(int i =0; i < n; ++i){
    int s;
    cin>>s;
    v[i] = s;
  }
  sort(v.begin(),v.end());
  if(v.front() == 1){
    cout<<-1<<endl;
  }else{
    cout<<1<<endl;
  }
}
