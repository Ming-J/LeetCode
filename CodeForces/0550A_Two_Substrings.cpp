#include <iostream>
#include <algorithm>
using namespace std;

bool checkSub(string in, string first, string sec){
  //xostring::iterator it;
  auto itre = find(in.begin(), in.end(), 'a');
  auto it = in.find(first);
  if( it != string::npos){
    if( in.find(sec,it+first.size()) != string::npos){
      return true;
    }
  }
  return false;
}

int main(){
  string input = "ABABA";
  cin>>input;
  bool check = checkSub(input, "AB", "BA") || checkSub(input, "BA", "AB");
  if(check){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}
