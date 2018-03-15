#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      string result;
      if(strs.size()==0){
	return result;
      }
      for(int j=0;j<strs[0].size();j++){
	char current=strs[0][j];
	for(int i=0;i<strs.size();i++){
	  if(current!=strs[i][j]){
	    return result;
	  }
	}
	result+=current;
      }
      return result;
    }
};


int main(){
  cout<<"Hello World"<<endl;
}
