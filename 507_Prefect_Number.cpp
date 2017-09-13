#include <iostream>
#include <math>
using namespace std;

class Solution{
public:
  bool checkPerfectNumber(int num){
    if(num<0){
      return false;
    }
    int total=0;
    for(int i=1;i<sqrt(num);i++){
      if(num%i==0){
	total+=i;
	if(num/i!=num){
	  total+=num/i;
	}
      }
    }
    if(total==num){
      return true;
    }
    return false;
  }
};

int main(){
  cout<<"Hello World"<<endl;
}
