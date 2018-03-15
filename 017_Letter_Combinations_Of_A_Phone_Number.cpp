#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<string> letterCombinations(string digits){
    if(digits.size()==0){
      return {};
    }
    vector<string> ans;
    vector<string> key
    {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    backtrack(ans,key,digits,0,"");
    return ans;
  }

  void backtrack(vector<string>& res,vector<string>& key, string digits,
		 int index,string combo){
    if(combo.size()==digits.size()){
      res.push_back(combo);
    }else{
      int keyi=digits[index]-'0';
      for(int i=0;i<key[keyi].size();i++){
	combo+=key[keyi][i];
	backtrack(res,key,digits,index+1,combo);
	combo.pop_back();
      }
    }
  }
};
