#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
  bool wordPattern(string pattern, string str){
    stringstream ss;
    ss.str(str);
    vector<string> strarray;
    string token;
    while(getline(ss,token,' ')){
      strarray.push_back(token);
    }
    if(pattern.size()!=strarray.size()){
      return false;
    }
    unordered_map<char,string> patternmap;
    unordered_map<string,char> stringmap;
    for(int i=0;i<strarray.size();i++){
      unordered_map<char,string>:: iterator got=patternmap.find(pattern[i]);
      unordered_map<string,char>:: iterator got2=stringmap.find(strarray[i]);
      if(got==patternmap.end()&&got2==stringmap.end()){
	patternmap[pattern[i]]=strarray[i];
	stringmap[strarray[i]]=pattern[i];
      }else{
	if(got==patternmap.end()||got2==stringmap.end()){
	  return false;
	}
	if(got->second!=strarray[i]||got2->second!=pattern[i]){
	  return false;
	}
      }
    }
    return true;
  }
};

int main(){
  Solution test;
  test.wordPattern("abba","dog dog dog dog");
}
