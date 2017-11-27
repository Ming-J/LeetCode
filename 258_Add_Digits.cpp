#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
  int addDigits(int num){
    while(num>=10){
      string temp=to_string(num);
      int sum=0;
      for(int i=0;i<temp.size();i++){
	sum+=(temp[i]-'0');
      }
      num=sum;
    }
    return num;
  }
};
