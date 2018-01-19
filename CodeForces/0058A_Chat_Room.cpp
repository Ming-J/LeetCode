#include <iostream>
using namespae std;

int main(){
  string str="ahhelllloou";
  //bool hH=false, hE=false, hL1=false, hL2=false, hO=false;
  cin>>str;
  string tar="hello";
  int i=0;
  int j=0;
  while(i<str.size()){
    if(tolower(str[i]) == str [j]){
      j++;
      if( j == tar.size() ){
	cout<<"YES"<<endl;
      }
    }
    i++;
  }
  cout<<"NO"<<endl;
}
