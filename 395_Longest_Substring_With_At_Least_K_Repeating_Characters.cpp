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
    return helper(s,k,0,s.size());
  }
  int helper(string s, int k, int start, int end){
    if(start > end){
      return 0;
    }
    unordered_map<char,int> arr;
    for(size_t i = start; i < end; ++i){
      arr[s[i]]++;
    }
    for(auto cur : arr){
      if(cur.second < k){
	for(size_t i = start; i < end; ++i){
	  if(s[i] == cur.first){
	    return max(helper(s,k,start,i),helper(s,k,i+1,end));
	  }
	}
      }
    }
    return end - start;
  }
};

int main(){
  Solution test;
  cout<<test.longestSubstring("ababbc",2)<<endl;
}
