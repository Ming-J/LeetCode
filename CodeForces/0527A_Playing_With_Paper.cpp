#include <iostream>
using namespace std;

/*
  a mm * b mm  a > b
  
  
*/

class Square{
public:
  static unsigned long long int calculate(unsigned long long int a,unsigned long long int b){
    unsigned long long int count = 0;
    while(a!=0&&b!=0){
      if(a>b){
	count += a/b;
	a = a%b;
      }else{
	count += b/a;
	b = b%a;
      }
    }
    return count;
  }
};

int main(){
  unsigned long long int a,b;
  cin>>a>>b;
  cout<<Square::calculate(a,b)<<endl;
}
