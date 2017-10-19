#include <iostream>
using namespace std;

class Solution{
public:
  bool detectCapitalUse(string word){
    bool allCap=true;
    bool allLow=true;
    bool firstCap=true;
    for(int i=0;i<word.size();i++){
      if(allCap&&isNotCap(word[i])){
	allCap=false;
      }
      if(allLow&&isCap(word[i])){
	allLow=false;
      }
      if(firstCap&&i==0&&isNotCap(word[i])){
	firstCap=false;
      }
      if(firstCap&&i!=0&&isCap(word[i])){
	firstCap=false;
      }
    }
    return allCap||allLow||firstCap;
  }

  bool isCap(char c){
    if(c>='A'&&c<='Z'){
      return true;
    }else{
      return false;
    }
  }

  bool isNotCap(char c){
    if(c>='a'&&c<='z'){
      return true;
    }else{
      return false;
    }
  }
};
