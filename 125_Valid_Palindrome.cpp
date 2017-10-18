#include <iostream>
#include <algorithm>
#include <stack>
#include <cctype>
using namespace std;

class Solution{
public:
  bool isPalindrome(string s){
    if(s.size()==0){
      return true;
    }
    transform(s.begin(),s.end(),s.begin(),::tolower);
    stack<char> deck;
    for(size_t i=0;i<s.size();i++){
      if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
	deck.push(s[i]);
      }
    }
    int i=deck.size()-1;
    for(size_t i=0;i<s.size();i++){
      if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
	cout<<s[i]<<endl;
	if(deck.top()!=s[i]){
	  return false;
	}
	deck.pop();
      }
    }
    return true;
  }
  bool isPali(string s){
    if(s.size()==0){
      return true;
    }
    int i=0;
    int j=s.size()-1;
    while(i<j){
      if(!isalnum(s[i])){
	i++;
      }else if(!isalnum(s[j])){
	j--;
      }else{
	if(toupper(s[i])!=toupper(s[j])){
	  return false;
	}
	i++;
	j--;
      }
    }
    return true;
  }
  
};

int main(){
  string t="abskdfgda#$%^&*()";
  transform(t.begin(),t.end(),t.begin(),::toupper);
  cout<<t<<endl;
}
