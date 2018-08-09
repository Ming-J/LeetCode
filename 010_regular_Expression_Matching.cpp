#include <iostream>
using namespace std;
/*
  input: string s
         string p
	 '.' matches any single characters
	 '*' Matches Zero or more of the preceding element
*/
class Solution {
public:
  bool isMatch(string s, string p) {
    //Base Case 
    if(p.size()==0){
      return s.size() == 0;
    }
    //Special Case
    if(p.size() == 1){
      //if the length of s is 0, return false
      if(s.size() < 1){
	return false;
      }
      // if the first does not match, return false;
      else if((p[0] != s[0]) && (p[0] != '.')){
	return false;
      }else{
	//Otherwise, compare the rest of the string of S and P
	return isMatch(s.substr(1), p.substr(1));
      }
    }
    //case 1: when the second char of p is not '*'
    if(p[1] != '*'){
      if(s.size() < 1){
	return false;
      }
      if((s[0] != p[0]) && (p[0]!='.')){
	return false;
      }else{
	return isMatch(s.substr(1),p.substr(1));
      }
    }else{ //when second char of p is '*'
      // a char & a '*' can stand for 0 element
      if(isMatch(s,p.substr(2))){
	return true;
      }
      int i = 0;
      while(i < s.length() && (s[i]==p[0] || p[0] == '.')){
	if(isMatch(s.substr(i+1),p.substr(2))){
	  return true;
	}
	++i;
      }
      return false;
    }
  }
};
