#include <iostream>
using namespace std;

bool checkP(int v){
  int sum = 0;
  while(v > 0){
    sum += (v%10);
    v /=10;
  }
  return sum==10;
}

int prefect(int k){
  int num = 0;
  while(k>0){
    ++num;
    if(checkP(num)){
      --k;
    }
  }
  return num;
}

int main(){
  int k;
  cin>>k;
  cout<<prefect(k)<<endl;
}
