/*===================================================== 
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to
get t.

All occurrences of a character must be replaced with another character
while preserving the order of characters. No two characters may map to
the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.

runtime complexity: O(N)
Space complexity: O(N)

Insert the two char into two different hash, and each new character
you insert, you check to see if it's already in the hash before and
compare the two hash. Two hashed are created for many to one relation
absd to aaaaa'
 =====================================================*/
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution{
public:
  bool isIsomorphic(string s, string t){
    unordered_map<char,char> charmap;
    unordered_map<char,char> charmap2;
    if(s.length()!=t.length()){
      return false;
    }
    for(int i=0;i<s.length();i++){
      unordered_map<char,char>::iterator it;
      unordered_map<char,char>::iterator it2;
      it=charmap.find(s[i]);
      it2=charmap2.find(t[i]);
      if(it!=charmap.end()&&it2!=charmap2.end()){
	if(it2->second!=it->first || it2->first!=it->second){
	  return false;
	}
      }else if(it!=charmap.end()||it2!=charmap2.end()){
	return false;
      }else{
	charmap[s[i]]=t[i];
	charmap2[t[i]]=s[i];
      }
    }
    return true;
  }
};

int main(){
  Solution test;
  if(test.isIsomorphic("ab","aa")){
    cout<<"asdsad"<<endl;
  }
  cout<<"Hello World"<<endl;
}
