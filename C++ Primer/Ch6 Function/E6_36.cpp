#include <iostream>
using namespace std;

string (&print(s))[10]{
  for(int i = 1; i < 10; ++i){
    string tot = str[i-1];
    str[i] = tot;
  }
  return str;
}

int main(){
  string input[10];
  input[0] = "st";
  string* tt = print(input);
  for(int i = 0; i < 10; ++i){
    cout<<*tt<<endl;
    tt += 1;
  }
}
