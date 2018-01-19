#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> deck;
      int rPN = 0;
      for( int i = 0; i < tokens.size(); i++){
	if( tokens[i] != "+" && tokens[i] != "-" &&
	    tokens[i] != "*" && tokens[i] != "/"){
	  deck.push(stoi(tokens[i]));
	}else{
	 int rhs = deck.top();
	 deck.pop();
	 int  lhs = deck.top();
	 deck.pop();
	 if ( tokens[i] == "+"){
	   deck.push(lhs + rhs);
	 }
	 if ( tokens[i] == "-"){
	   deck.push(lhs - rhs);
	 }
	 if ( tokens[i] == "*"){
	   deck.push(lhs * rhs);
	 }
	 if ( tokens[i] == "/"){
	   deck.push(lhs / rhs);
	 }	
	}
      }
      return deck.top();
    }
};
