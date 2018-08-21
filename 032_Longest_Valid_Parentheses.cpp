#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    if(s.empty()) return 0;
    stack<int> paren;
    for(size+t i = 0; i < s.size(); ++i){
      if(s[i] == '(') paren.push(i);
      else{
	if(!paren.empty() && s[paren.top()] == ')') paren.pop();
	else paren.push(i);
      }
    }
    if(paren.empty()) return s.size();
    else{
      
    }
  }
};
