#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
int main(){
  int drinks;
  cin>>drinks;
  int sum = 0;
  for( int i = 0; i < drinks; ++i){
    int n;
    cin>>n;
    sum += n;
  }  
  cout<<std::setprecision(10)<<(sum)*1.0/drinks<<endl;
}
