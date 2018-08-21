#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    if(s.empty()) return 0;
    stack<int> paren;
    //Scan the string, removing all the valid Parentheses
    for(size_t i = 0; i < s.size(); ++i){
      if(s[i] == '(') paren.push(i);
      else{
	if(!paren.empty() && s[paren.top()] == '(') paren.pop();
	else paren.push(i);
      }
    }
    //Stack are left with indeices of invalid parentheses
    //So substring of left or right are valid parentheses
    //Calculate the length of substring
    if(paren.empty()) return s.size();
    else{
      int lo = 0, hi = s.size();
      int maxLength = 0;
      while(!paren.empty()){
	int lo = paren.top();
	paren.pop();
	maxLength = max(maxLength, hi - lo - 1);
	hi = lo;
      }
      return max(maxLength, hi);
    }
  }
};
