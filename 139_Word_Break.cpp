#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    bool dp [s.size()+1] = {false};
    for(int i = 1; i <= s.size();i++){
      cout<<s.substr(0,i)<<endl;
    }
    for(string s : wordDict){
      cout<<s<<endl;
    }
    return true;   
  }
};


int main(){
  Solution test;
  vector<string> inp = {"leet","code"};
  test.wordBreak("leetcode", inp);
}
