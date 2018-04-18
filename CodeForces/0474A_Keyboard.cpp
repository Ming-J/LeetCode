#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
  vector<string> strs = {"@qwertyuiop@","@asdfghjkl;@","@zxcvbnm,./@"};
  char c;
  cin>>c;
  unordered_map<char,char> hash;
  for(auto s: strs){
    if(c=='L'){
      for(size_t i = 1; i < s.size()-1; ++i){
	hash.insert({s[i-1],s[i]});
      } 
    }else{
       for(size_t i = 1; i < s.size()-1; ++i){
	 hash.insert({s[i+1],s[i]});
      } 
    }
  }
  string str;
  cin>>str;
  for(auto c : str){
    if(hash[c] != '@'){
      cout<<hash[c];
    }
  }
}
