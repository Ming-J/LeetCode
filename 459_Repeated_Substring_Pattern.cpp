/*========================================================================
Given a non-empty string check if it can be constructed by taking a
substring of it and appending multiple copies of the substring
together. You may assume the given string consists of lowercase
English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.

Example 2:
Input: "aba"
Output: False

Example 3:
Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring
"abcabc" twice.)

Only beat 21 precent of people, need to learn about the KMP algorithm
time complexity:O(m+n/2)?
space complexity:O(m+n/2)?

The method I used used is brute force. So I know the max size of
substring that can be repeated is when s.size is half. So I start
decrement from the half way point. If the number of substring is
module of the input string, then we know the input string is
repeatable by the given size of substring. So I would break up the
string according to the substring and store all substring in
vector. Then I would check to see if all the substring are the same.
=========================================================================*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
  bool repeatedSubstringPattern(string s){
    if(s.size()==1){
      return false;
    }
    int length=s.size();
    for(int i=length/2;i>0;i--){
      if(length%i==0){
	int ssubbegin=0;
	int ssubend=i;
	vector<string> substringcollection;
	while(ssubbegin<length){
	  string ssub=s.substr(ssubbegin,i);
	  substringcollection.push_back(ssub);
	  ssubbegin=ssubbegin+i;
	}
	bool temp=true;
	for(int j=1;j<substringcollection.size();j++){
	  cout<<j<<substringcollection.size()<<endl;
	  cout<<substringcollection[0]<<" "<<substringcollection[j]<<endl;
	  if(substringcollection[0]!=substringcollection[j]){
	    temp=false;
	  }
	}
	if(temp==true){
	  //cout<<substringcollection[0]<<endl;
	  return true;
	}
      }
    }
    return false;
  }
};

int main(){
  cout<<"Hello World"<<endl;
  Solution test;
  string s="aba";
  test.repeatedSubstringPattern(s);
}
