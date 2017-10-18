#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

class Solution{
public:
  string reverseVowels(string s){
    if(s.size()==0){
      return s;
    }
    //transform(s.begin(),s.end(),s.begin(),::tolower);
    int i=0;
    int j=s.size()-1;
    while(i<j){
      
      if(!checkVow(s[i])){
	i++;
      }else if(!checkVow(s[j])){
	j--;
      }else{
	swap(s[i],s[j]);
	i++;
	j--;
      }
    }
    return s;
  }

  bool checkVow(char c){
    if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&
       c!='A'&&c!='E'&&c!='I'&&c!='O'&&c!='U'){
      return false;
    }else{
      return true;
    }
  }
};

int main(){
  Solution test;
  cout<<test.reverseVowels("leetcode")<<endl;
}
