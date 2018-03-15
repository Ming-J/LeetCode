#include <iostream>
using namespace std;

string arr[10];

//tailling return
//easy to understand
auto func(int i) ->string(&)[10]{
  arr[i] ="Hello";
  return arr;
}

//using alias
using string_alias = string[10];
string_alias& func2(int i){
  arr[i]="alias";
  return arr;
}

//using decltype
decltype(arr)& func1(int i){
  arr[i] = "decltype";
  return arr;
}




int main(){
  
  for(auto s:func(3)){
    cout<<s<<endl;
  }

  for(auto s:func1(8)){
    cout<<s<<endl;
  }
  
  for(auto s:func2(6)){
    cout<<s<<endl;
  }
  
}
