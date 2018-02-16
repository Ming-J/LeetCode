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
      //vector<string> heap;
      stack<string>  deck;
      while(getline(ss, token, ',')){
	deck.push(token);
      }
      while(deck.size()>=3){
	if(deck.top() == "#"){
	  deck.pop();
	  if(deck.top() != "#"){
	    return false;
	  }else{
	    deck.pop();
	    deck.pop();
	    deck.push("#");
	  }
	}else{
	  return false;
	}
      }
      return true;




      
      while(!deck.empty()){
	cout<<deck.top()<<" ";
	deck.pop();
      }
      if(deck.size() != 1 || deck.top() != "#"){
	return false;
      }
      return true;
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
