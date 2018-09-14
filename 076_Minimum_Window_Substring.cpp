#include <iostream>
#include <limits>
#include <unordered_map>
using namespace std;

class Solution{
public:
  string minWindow(string s, string t){
    unordered_map<char,int> chrArray;
    for(char c:t){
      ++chrArray[c];
    }
    string substr;
    int lo = 0, hi = 0, chrCount = 0, minLen = numeric_limits<int>::max();
    while(hi<s.size()){
      char cur = s[hi];
      //cur existed in T, update hash map
      if(chrArray.find(cur)!=chrArray.end()){
	if(chrArray[cur]>0) chrCount++;
	--chrArray[cur];
      }
      ++hi;
      //Have a substring that contains all T characters
      while(chrCount == t.size()){
	char locur = s[lo];
	// Checking to see if lo character is in T
	if(chrArray.find(locur)!=chrArray.end()){
	  //
	  if(chrArray[locur] == 0) --chrCount;
	  ++chrArray[locur];
	  int curLength = hi - lo;
	  if(minLen >= curLength){
	    substr=s.substr(lo,hi-lo);
	    cout<<substr<<endl;
	    minLen = curLength;
	  }
	}
	lo++;
      }
    }
    return substr;
  }
};

int main(){
  Solution s;
  s.minWindow("ADOBECODEBANC", "ABC");
  
}
