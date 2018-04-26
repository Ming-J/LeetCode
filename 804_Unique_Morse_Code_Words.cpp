#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
      vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....",
			  "..",".---","-.-",".-..","--","-.","---",".--.",
			  "--.-",".-.","...","-","..-","...-",".--","-..-",
			  "-.--","--.."};
      unordered_set<string> unique;
      for(string s: words){
	string mc="";
	for(char c:s){
	  mc += code[c-'a'];
	}
	unique.insert(mc);
      }
      return unique.size();
    }
};
