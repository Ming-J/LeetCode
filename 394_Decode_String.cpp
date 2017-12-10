#include <iostream>
#include <stack>
using namespace std;
/*
Solved this problem iteratively using stack. One stack to keep track
of number and another on to keep tack of string and iterating through
the screen.
*/
class Solution{
public:
  string decodeString(string s){
    string ans="";
    stack<int> numberDeck;
    stack<string> letterDeck;
    string current="";
    for(int i=0;i<s.size();i++){
      if(s[i]=='['){
	string num="";
	for(int k=i-1;i>=0&&s[k]-'0'<10;k--){
	  num=s[k]+num;
	  current.pop_back();
	}
	numberDeck.push(stoi(num));
	letterDeck.push(current);
	current.erase();
      }else if(s[i]==']'){
	int rep=numberDeck.top();
	numberDeck.pop();
	string t=letterDeck.top();
	letterDeck.pop();
	for(int j=0;j<rep;j++){
	  t+=current;
	}
	current=t;
      }else{
	current+=s[i];
      }      
    }
    return ans+current;
  }
};
