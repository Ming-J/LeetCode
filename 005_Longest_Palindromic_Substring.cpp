#include <iostream>
using namespace std;

bool isPalindrom(string s,int i,int j){
  while(i<j){
    if(s[i]!=s[j]){
      return false;
    }else{
      i++;j--;
    }
  }
  return true;
}

class Solution{
public:
  string longestPalindrome(string s){
    string maxP="";
    for(int i=0;i<s.size();i++){
      for(int j=i;j<s.size();j++){
	if(isPalindrom(s,i,j)){
	  if(maxP.size()<j-i+1){
	    maxP=s.substr(i,j-i+1);
	  }
	}
      }
    }
    return maxP;
  }
};
