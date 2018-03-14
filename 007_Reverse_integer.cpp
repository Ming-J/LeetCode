#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution{
public:
  int reverse(int x){
    double ans=0;
    while(x!=0){
      ans = ans * 10 + x % 10;
      if(ans>INT_MAX||ans<INT_MIN){
	return 0;
      }
      x/=10;
    }
    return (int)ans;
  }
};

int main(){
  cout<<"Hello World"<<endl;
  Solution test;
  cout<<test.reverse(-1123400245)<<endl;
}
