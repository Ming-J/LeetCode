#include <iostream>
using std::cin;
using std::cout;
int main(){
  int inputs;
  cin>>inputs;
  int officers = 0;
  int untreated = 0;
  for(int i =0; i < inputs; ++i){
    int c;
    cin>>c;
    if(c != -1){
      officers += c;
    }else{
      if(officers > 0){
	--officers;
      }else{
	++untreated;
      }
    }
  }
  cout<<untreated;
}
