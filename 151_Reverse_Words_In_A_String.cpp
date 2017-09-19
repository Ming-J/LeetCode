#include <iostream>
using namespace std;

class Solution{
public:
  void reverseWords(string &s){
    int size=s.size();
    int previousSpace=0;
    int wordLength=0;
    string result="";
    for(int i=size-1;i>=0;i--){
      if(s[i]!=' '){
	wordLength++;
      }else{
	if(wordLength>0){
	  if(result==""){
	    result+=s.substr(i+1,wordLength);
	  }else{
	    result+=' '+s.substr(i+1,wordLength);
	  }
	  wordLength=0;
	}
      }
      if(i==0&&wordLength>0){
	if(result==""){
	  result+=s.substr(i,wordLength);
	}else{
	  result+=' '+s.substr(i,wordLength);
	}
      }
    }
    s=result;
  }
};
