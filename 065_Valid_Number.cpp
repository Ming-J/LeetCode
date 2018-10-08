#include <iostream>
using namespace std;

class Solution {
public:
  bool isNumber(string s) {
    int state = 0;
    bool prefix = false;
    for(char c : s){
      if(state == 0){
	if(isPosOrNeg(c)){
	  state = 1;
	}else if(isdigit(c)){
	  state = 2;
	}else if(isDot(c)){
	  state = 6;
	}else if(isSpace(c)){
	  state = 0;
	}else return false;
      }else if(state == 1){
	if(isdigit(c)){
	  state = 2;
	}else if(isDot(c)){
	  state = 6;
	}else return false;
      }else if(state == 2){
	if(isdigit(c)){
	  state = 2; 
	}else if(isSpace(c)){
	  state = 8;
	}else if(isExp(c)){
	  state = 3;
	}else if(isDot(c)){
	  prefix = true;
	  state = 6;
	}else return false;
      }else if(state == 3){
	if(isdigit(c)){
	  state = 5;
	}else if(isPosOrNeg(c)){
	  state = 4;
	}else return false;
      }else if(state == 4){
	if(isdigit(c)) state = 5;
	else return false;
      }else if(state == 5){
	if(isdigit(c)) state = 5;
	else if(isSpace(c)) state = 8;
	else return false;
      }else if(state == 6){
	if(isdigit(c)) state = 7;
	else if(prefix&&isExp(c)) state = 3;
	else if(prefix&&isSpace(c)) state = 8;
	else return false;
      }else if(state == 7){
	if(isdigit(c)) state = 7;
	else if(isExp(c)) state = 3;
	else if(isSpace(c)) state = 8;
	else return false;
      }else if(state == 8){
	if(isSpace(c)) state = 8;
	else return false;
      }
    }
    return (state == 2 || state == 5 || (prefix && state == 6)||state == 7 || state == 8);
  }

private:
  bool isPosOrNeg(char c){
    return c=='+'||c=='-';
  }

  bool isDot(char c){
    return c=='.';
  }

  bool isExp(char c){
    return c=='e'||c=='E';
  }

  bool isSpace(char c){
    return c==' ';
  }
  
};
