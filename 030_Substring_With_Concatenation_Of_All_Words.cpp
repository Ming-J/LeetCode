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
    for(auto w : words){
      ++wordsCount[w];
    }
    for(int i = 0; i < s.size(); ++i){
      unordered_map<string,int> indexCheck(wordsCount);
      for(int j = i; j < s.size(); j += wordSize){
	string sub = s.substr(j,wordSize);
	if(indexCheck.find(sub) != indexCheck.end()){
	  if(--indexCheck[sub] == 0) indexCheck.erase(sub);
	}else break;
	//cout<<s.substr(j,wordSize)<<endl;
      }
      if(indexCheck.empty() == 0) res.push_back(i);
      //cout<<endl;
    }
    return res;
  }
};

int main(){
  Solution test;
  string input = "barfoothefoobarman";
  vector<string> arr = {"foo","bar"};
  test.findSubstring(input,arr);
}
