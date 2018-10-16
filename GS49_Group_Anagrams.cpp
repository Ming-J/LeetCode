#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<int> ok;
    unordered_map< string,vector<string> > res;
    for(string token: strs){
      vector<int> charArray(26,0);
      for(char c: token){
	++charArray[c-'a'];
      }
      string vectStr = "";
      for(int i : charArray){
	vectStr.append(to_string(i));
      }
      res[vectStr].push_back(token);
    }
    vector< vector<string> > ans;
    for(auto pa : res){
      ans.push_back(pa.second);
    }
    return ans;
  }
};
