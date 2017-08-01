/**************************************************
Given a string, find the length of the longest substring without
repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that
the answer must be a substring, "pwke" is a subsequence and not a
substring.

***************************************************/
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
public:
  int lengthOfLongestSubstring(string s){
    int current=0;
    int max=0;
    unordered_map<char,int> chararr;
    unordered_map<char,int>::iterator it;
    for(int i=0;i<s.size();i++){
      it=chararr.find(s[i]);
      if(it==chararr.end()){
	chararr[s[i]]=i;
	current++;
	if(current>max){
	  max=current;
	}
      }else{
	current=0;
	i=chararr[s[i]];
	chararr.clear();
      }
    }
    return max;
  }
};

int main(){
  Solution test;
  cout<<test.lengthOfLongestSubstring("abcabcbb")<<endl;
  cout<<test.lengthOfLongestSubstring("bbbbb")<<endl;
  cout<<test.lengthOfLongestSubstring("pwwkew")<<endl;
}
