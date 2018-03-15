#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
  bool isValid(string s) {
    if(s.size()%2!=0){
      return false;
    }
    stack<char> deck;
    for(int i=0;i<s.size();i++){
      if(s[i]==')'||s[i]=='}'||s[i]==']'){
	if(!deck.empty()){
	  char t=deck.top();
	  bool c1=s[i]==')'&&t=='('; 
	  bool c2=s[i]=='}'&&t=='{'; 
	  bool c3=s[i]==']'&&t=='['; 
	  if(c1||c2||c3){
	    deck.pop();
	  }else{
	    return false;          
	  }
	}else{
	  return false;  
	}
      }else{
        deck.push(s[i]);   
      } 
    }
    if(deck.empty()){
      return true;
    }else{
      return false;
    } 
  }
};

int main(){
  cout<<"Hello World"<<endl;
}
