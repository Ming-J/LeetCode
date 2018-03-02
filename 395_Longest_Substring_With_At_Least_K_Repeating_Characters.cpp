#include <iostream>
#include <unordered_map>
using namespace std;
//Find all substring, and check each hash
class BruteForceSolution {
public:
  int longestSubstring(string s, int k) {
    size_t maxLength = 0;
    for(size_t i = 0; i < s.size(); i++){
      string subst;
      for(size_t j = i; j < s.size(); j++){
	unordered_map<char,int> arr;
	subst = s.substr(i, (j - i) + 1);
	for( char c : subst){
	  arr[c]++;
	}
	bool checkMax = true;
	for( auto num : arr){
	  if(num.second < k){
	    checkMax = false;
	  } 
	}
	if(checkMax){
	  maxLength = max(maxLength,subst.size());
	}
      }
    }
    return maxLength;
  }
};

class Solution {
public:
  int longestSubstring(string s, int k) {
    int maxLength = 0;
    unordered_map<char,int> arr;
    for( char c : s){
      arr[c]++;
    }
    bool checkMax = true;
    for(size_t i = 0; i < s.size(); i++){
      if(arr[s[i]] < k){
	checkMax = false;
	maxLength = max(longestSubstring(s.substr(0,i),k),
		       longestSubstring(s.substr(i+1),k));
      }
    }
    return checkMax? s.size() : maxLength;
  }
};

int main(){
  Solution test;
  cout<<test.longestSubstring("ababbc",2)<<endl;
}
