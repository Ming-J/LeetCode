#include <iostream>
using namespace std;

class Solution{
public:
  bool isPalindrome(int x){
    string num=to_string(x);
    if(num.size()==0||num.size()==1){
      return true;
    }
    int j=num.size()-1;
    for(int i=0;i<num.size();i++){
      if(num[i]!=num[j]){
	return false;
      }else{
	j--;
      }
    }
    return true;
  }
};
