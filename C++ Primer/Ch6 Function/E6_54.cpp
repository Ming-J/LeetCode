/*
Write a declaration for a function that takes two int parameters and
returns a n int, and declare a vector whose elements have this
function pointer type.
*/
#include <iostream>
#include <vector>
using namespace std;

int multi(int a, int b){
  cout<<"Mutiply:";
  return a*b;
}
int add(int a, int b){
  cout<<"Addition:";
  return a+b;
}
int subtract(int a, int b){
  cout<<"Subtract:";
  return a-b;
}
int divide(int a, int b){
  cout<<"Divide:";
  return a/b;
}
using F = int(*)(int,int);

int main(){
  //Using type alias declarations
  vector<F> assign;
  assign.push_back(multi);
  assign.push_back(add);
  cout<<assign[0](2,3)<<endl;
  cout<<assign[1](4,5)<<endl;

  vector<decltype(multi)*> a2;
  a2.push_back(add);
  cout<<"Using decltype to simplify"<<endl;
  cout<<a2[0](10,10)<<endl;

  //Declaring directly
  vector<int(*)(int,int)> a1;
  a1.push_back(multi);
  cout<<"Declaring Directly"<<endl;;
  cout<<a1[0](12,12)<<endl;

  //5,5
  cout<<"E6_56"<<endl;
  typedef int (*PF)(int,int);
  vector<PF> ff={add,subtract,multi,divide};
  for(auto k : ff){
    cout<<k(5,5)<<endl;
  }
  
}
