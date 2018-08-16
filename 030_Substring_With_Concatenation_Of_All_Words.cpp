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
      for(int j = i; j < s.size(); j += wordSize){
	cout<<s.substr(j,j+wordSize());
      }
    }
    return res;
  }
};

int main(){
  

}
