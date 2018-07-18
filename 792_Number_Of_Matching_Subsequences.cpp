#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
  Using Index + Binary Search
  Using unordered_map to store all the index,
  abca
  a : [0,3]  b:[1] c : [2]
  then for each word check to see if you can get the index in sequence
  for each character in word, use binary search to find the index in sequence

  Time Complexity: O(S)+ O(W*L*log(S))
  Space Complexity: O(S)
*/
class Solution {
public:
  int numMatchingSubseq(string S, vector<string>& words) {
    int count = 0;
    unordered_map<char, vector<int> > charMap;
    for(size_t i = 0; i < S.size(); ++i){
      charMap[S[i]].push_back(i);
    }  
    auto func = [&charMap](string w){
      int prev = -1;
      for(char c : w){
	/*lower_bound : return iterator pointing to the first element that is not less than
	  value (greater or equal)
	  upper_bound: return iterator pointing to the first element that is greater than value
	*/
	auto index = lower_bound(charMap[c].begin(),charMap[c].end(),prev+1);
	if(index == charMap[c].end()) return false;
	prev = *index;
      }
      return true;
    };
    return count_if(words.begin(),words.end(),func);
  }
};


int main(){
  Solution test;
  vector<string> words={"a","bb","acd","ace"};
  cout<<test.numMatchingSubseq("abcde",words)<<endl;;
  
}
