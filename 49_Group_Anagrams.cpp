#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  vector<vector<string> > groupAnagrams(vector<string>& strs){
    //using unordered_map to store the anagrams string
    unordered_map< string, vector<string> > hash;
    for(size_t i=0;i<strs.size();i++){
      /*finding the count of each character and convert them to string
	to use as key*/
      vector<char> alpha(26,0);
      for(size_t j=0;j<strs[i].size();j++){
	alpha[strs[i][j]-'a']++;
      }
      string key="";
      for(size_t j=0;j<alpha.size();j++){
	key+=to_string(alpha[j]);
      }
      hash[key].push_back(strs[i]);
    }
    vector< vector<string> > ans;
    for(auto i=hash.begin();i!=hash.end();i++){
      ans.push_back(i->second);
    }
    return ans;
  }
};
