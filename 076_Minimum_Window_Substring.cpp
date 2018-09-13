#include <iostream>
using namespace std;

class Solution{
public:
  string minWindow(string s, string t){
    vector<int> chr(256);
    for(char c:t){
      ++chr[c];
    }
    vector<int> chr2(256);
    int lo = 0, hi = 0, chrCount = 0;
    while(hi<s.size()){
      if(chr[s[hi]] > 0) ++chr2[s[hi]];
      if
    }
  }
};
