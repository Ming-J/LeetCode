#include <iostream>
using namespace std;

class Solution{
public:
  int countSegments(string s){
    int seg=0;
    bool flag=false;
    for(int i=0;i<s.size();i++){
      if(flag){
	if(s[i]==' '){
	  flag=false;
	}
      }else{
	if(s[i]!=' '){
	  flag=true;
	  seg++;
	}
      }
    }
    return seg;
  }
};
