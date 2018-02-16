#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
      stringstream ss(preorder);
      string token;
      stack<string>  deck;
      while(getline(ss, token, ',')){
	if(token == "#"){
	  checkTop(deck);
	}else{
	  deck.push(token);
	}
      }
      if(deck.size() == 1 && deck.top() == "#"){
	return true;
      }else{
	return false;
      }
    }
  void printdeck(stack<string> deck){
    while(!deck.empty()){
      cout<<deck.top()<<' ';
      deck.pop();
    }
    cout<<endl;
  }
  void checkTop(stack<string> &deck){
    //printdeck(deck);
    if(deck.size()>1&&deck.top() == "#"){
      deck.pop();
      if(deck.top()!="#"){
	deck.pop();
	checkTop(deck);
      }else{
	deck.push("#");
      }
    }else{
      deck.push("#");
    }
  }
};


int main(){
  Solution test;
  if(test.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#")){
    cout<<"True"<<endl;
  }else{
    cout<<"False"<<endl;
  }
}
