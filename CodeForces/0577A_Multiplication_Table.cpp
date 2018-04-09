#include <iostream>
using namespace std;

int calDuplicate(int n, int val){
  if(val == 1) return 1;
  int same = 0;
  for(size_t i = 1; i <= n; ++i){
    if(val%i == 0 && val/i <= n ){
      same += 1;
    }
  }
    return same;
}

int main(){
  int n, val;
  cin>>n>>val;
  cout<<calDuplicate(n,val)<<endl;
}
