#include <iostream>
#include <vector>
using namespace std;


int main(){
  int aLength, bLength;
  int aChoose, bChoose;
  cin>>aLength>>bLength;
  cin>>aChoose>>bChoose;
  int t;
  int aMax;
  for(int i = 0; i < aLength; ++i){
    cin>>t;
    if(aChoose == i + 1){
      aMax = t;
    }
  }
  int biggerA = 0;
  for(int i = 0; i < bLength; ++i){
    cin>>t;
    if(aMax < t){
      ++biggerA;
    }
  }
  if(biggerA >= bChoose){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}
