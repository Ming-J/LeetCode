#include <iostream>
using namespace std;

int main(){
  int songs, times, jokes = 0;
  cin>>songs>>times;
  for(int i = 0; i < songs; ++i){
    int temp;
    cin>>temp;
    times -= temp;
    if(i != songs - 1){
      times -= 10;
      jokes += 2;
    }
  }
  if(times >= 0){
    jokes += (times/5);
  }else{
    jokes = -1;
  }
  cout<<jokes<<endl;
}
