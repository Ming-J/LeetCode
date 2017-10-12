#include <iostream>
using namespace std;

class Solution{
public:
  string reverseWords(string s){
    if(s.size()==0){
      return s;
    }
    bool wordOn=false;
    int front;
    int back;
    for(size_t i=0;i<s.size();i++){
      if(!wordOn){
	if(s[i]!=' '){
	  front=i;
	  wordOn=true;
	}
      }
      if(wordOn){
	if(s[i]==' '){
	  back=i-1;
	  wordOn=false;
	  swapword(s,front,back);
	}
      }
    }
    if(wordOn){
      swapword(s,front,s.size()-1);
    }
    return s;
  }
  void swapword(string &s,int begin, int back){
    while(back>begin){
      swap(s[begin],s[back]);
      begin++;
      back--;
    }
  }
};

int main(){
  Solution test;
  cout<<test.reverseWords("Let's do some leetcode!")<<endl;
}
