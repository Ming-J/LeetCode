#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if(s.empty() || words.empty()) return res;
    unordered_map<string, int> wordsCount;
    int wordSize = words[0].size();
    int wordCount = words.size();
    //Getting the count of each word's occurence'
    for(auto w : words){
      ++wordsCount[w];
    }
    //Sliding Window, We check each starting index until our words
    //concatnated string a longer
    for(int i = 0; i < s.size() - wordSize * wordCount + 1; ++i){
      unordered_map<string,int> indexCheck(wordsCount);
      //Breaking up the string into same same as the words vector
      for(int j = i; j < s.size(); j += wordSize){
	string sub = s.substr(j,wordSize);
	//Decrease the hashmap count until the word is no longer
	//in the string
	if(indexCheck.find(sub) != indexCheck.end()){
	  if(--indexCheck[sub] == 0) indexCheck.erase(sub);
	}else break;
      }
      //Hashmap empty meaning the string contain all substring in word
      if(indexCheck.empty()) res.push_back(i);
    }
    return res;
  }
};

int main(){
  Solution test;
  string input = "barfoothefoobarman";
  vector<string> arr = {"foo","bar"};
  for(auto i : test.findSubstring(input,arr)){
    cout<<i<<endl;
  }
}
