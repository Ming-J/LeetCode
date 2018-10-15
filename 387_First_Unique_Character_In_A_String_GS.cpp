#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int firstUniqChar(string s){
    vector<int> hash(26,0);
    for(size_t i = 0; i < s.size(); ++i){
      ++hash[s[i]-'a'];
    }
    for(size_t i = 0; i < s.size(); ++i){
      if(hash[s[i]-'a'] == 1) return i;
    }
    return -1;
  }
};
