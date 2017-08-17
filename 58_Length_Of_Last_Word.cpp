#include <iostream>
using namespace std;

class Solution{
public:
  int lengthOfLastWord(string s){
    int count=0;
    for(int i=s.size()-1;i>=0;i--){
      if(s[i]==' '&&i==s.size()-1){
	while(s[i-1]==' '&&i>=1){
	  i++;
	}
      }else if(s[i]==' '){
	return count;
      }else{
	count++;
      }
    }
      return count;
  }
};
