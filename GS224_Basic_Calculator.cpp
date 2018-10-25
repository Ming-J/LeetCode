#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  int calculate(string s) {
    int num = 0;
    int val = 0;
    stack<int> sign;
    sign.push(1);
    int addOrSub = 1;
    for(char &c : s){
      if(isdigit(c)){
	num = num * 10 + (c - '0');
      }else{
	if(c == '+' || c== '-'){
	  val = val + (num * sign.top() * addOrSub);
	  num = 0;
	  addOrSub = (c=='+')?1:-1;
	}else if(c=='('){
	  sign.push(sign.top()*addOrSub);
	  addOrSub = 1;
	}else if(c==')'){
	  val = val + (num * sign.top() * addOrSub);
	  num = 0;
	  sign.pop();
	  addOrSub = 1;
	}
      }
    }
    if(num != 0) val = val +(num*sign.top()*addOrSub);
    return val;
  }
};

int main(){
  Solution t;
  cout<<t.calculate("2-1 + 2")<<endl;
}
