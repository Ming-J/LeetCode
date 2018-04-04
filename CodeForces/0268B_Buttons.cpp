#include <iostream>
using namespace std;

int main(){
  int button;
  cin>>button;
  int pressed = button;
  for(int i = 1; i <= button; ++i){
    pressed += ((button-i)*i);
  }
  cout<<pressed<<endl;
}
