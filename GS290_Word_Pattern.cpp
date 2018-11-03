#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string str) {
    stringstream iss(str);
    unordered_map<char, string> hash;
    unordered_set<string> set;
    string word;
    int i = 0;
    for(string word; iss>>word; ++i){
      if(i==pattern.size()) return false;
      if(hash.find(pattern[i]) == hash.end()&&set.find(word)==set.end()){
	hash.insert(make_pair(pattern[i],word));
	set.insert(word);
      }else{
	if(hash[pattern[i]] != word) return false;
      }
    }
    return true;
  }
};

int main(){
  string str = "dog cat cat dog";
  stringstream iss(str);
  while(iss){
    string s;
    iss>>s;
    cout<<s<<endl;
  }
}
