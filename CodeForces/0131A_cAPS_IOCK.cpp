#include <iostream>
#include <algorithm>
using namespace std;

int main(){

  string pos = "Lock";
  cin>>pos;
  bool capLock = true;
  
  for(int i = 1; i < pos.size(); i++){
    if( pos[0] >= 'A' && pos[0] <= 'Z'){
      if(pos[i] >= 'a' && pos[i] <= 'z'){
	capLock = false;
      }
    }else{
      if(pos[i] >= 'a' && pos[i] <= 'z'){
	capLock = false;
      }
    }
  }

  if(!capLock){
    cout<<pos;
  }else{
    for ( int i = 0 ; i < pos.size() ; i++){
      if(pos[i] >= 'a' && pos[i] <= 'z'){
	pos[i] = toupper(pos[i]);
      }else{
	pos[i] = tolower(pos[i]);
      }
    }
    //transform(pos.begin(),pos.begin()+1,pos.begin(),::toupper);
    //transform(pos.begin()+1,pos.end(),pos.begin()+1,::tolower);
    cout<<pos<<endl;
  }
}
