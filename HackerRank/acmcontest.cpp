#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

int main(){
  int n;
  int number;
  getline(cin,n);
  for(int i=0;i<n;i++){
    getline(cin,number);
    cout<<number<<endl;
  }
  return 0;
}
