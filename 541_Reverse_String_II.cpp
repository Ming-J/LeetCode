#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  string reverseStr(string s, int k) {
    int index = 0;
    bool reverse = true;
    while( index < s.size() ){
      if(reverse){
	int end = index+k-1;
	if( end >= s.size()){
	  end = s.size()-1;
	}
	helper( s, index, end);
	reverse = false;
      }else{
	reverse = true;
      }
      index += k; 
    }
    return s;
  }
  
  void helper(string &str, int begin, int end){
    while(end > begin){
      swap(str[begin],str[end]);
      begin++;
      end--;
    }
  }
};
