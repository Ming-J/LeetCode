#include <iostream>
using namespace std;

class Solution{
public:
  int myAtoi(string str){
    if(str.size()==0){
      return 0;
    }
    int start=0;
    while(str[start]==' '){
      start++;
    }
    if(start==str.size()||((str[start]=='-'||str[start]=='+')&&
      (str[start+1]=='-'||str[start+1]=='+'))){
      return 0;
    }
    bool neg=true;
    if(str[start]=='-'||str[start]=='+'){
      neg=false;
    }
    int ans=0;
    if(neg){
      ans=convert(str,start,'+'); 
    }else{
      ans=convert(str,start+1,str[start]);
    }
    return ans;
  }
  
  int convert(string num,int start,char sign){
    int ans=0;
    int dec=0;
    for(int i=start;i<num.size();i++){
      int digit=checkNum(num[i]);
      if(digit!=-1){
	dec++;
	ans*=10;
	if((ans>=2147483640&&digit>7&&sign=='+')||
	   (ans>=2147483640&&digit>8&&sign=='-')||dec<=10){
	  return (sign=='+')?2147483647:-2147483648;
	}else{
	  ans+=digit;
	}
      }else{
	break;
      }
    }
    return (sign=='+')?ans:ans*-1;
  }
  
  int checkNum(char c){
    int range=c-'0';
    if(range>=0&&range<=9){
      return range;
    }else{
      return -1;
    }
  }
};

