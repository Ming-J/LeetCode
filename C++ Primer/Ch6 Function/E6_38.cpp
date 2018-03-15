#include <iostream>
using namespace std;

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
decltype(odd)& arrRef(int i){
  return (i%2==0)?even:odd;
}

auto tailingRef(int i) -> int(&)[5]{
  return (i%2==0)?even:odd;
}


int main(){
  for(auto i : arrRef(7)){
    cout<<i<<endl;
  }
  cout<<endl;
  for(auto i : arrRef(4)){
    cout<<i<<endl;
  }
  
}
