#include <iostream>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int i = 0;
    int j = 0;
    int match = 0;
    int star = -1;
    while(i<s.size()){
      if(s[i]==p[j] || p[j] == '?'){
	++i;
	++j;
	continue;
      }
      if(j<p.size()&&p[j] == '*'){
	  star = j++;
	  match = i;
	  continue;
      }
      if(star != -1){
	j = star + 1;
	++match;
	i = match;
	continue;
      }
      return false;
    }
    while(j<p.size()&&p[j]=='*') ++j;
    return j == p.size();
  }
};
