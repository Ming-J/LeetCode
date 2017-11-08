#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<string> restoreIpAddresses(string s){
    vector<string> ans;
    backtrack(ans,"",0,s,0);
    return ans;
  }

  void backtrack(vector<string>& res,string address,int part,string s,
		 int startI){
    if(part>4){return;}
    if(part==4&&address.size()==s.size()+3){
      res.push_back(address);
    }else{
      string n="";
      for(int i=startI;i<3+startI&&i<s.size();i++){
	n+=s[i];
	int temp=stoi(n);
	if(temp<256&&temp>=0){
	  if(part<3){
	    backtrack(res,address+to_string(temp)+'.',part+1,s,i+1);
	  }else{
	    backtrack(res,address+to_string(temp),part+1,s,i+1);
	  }
	}else{
	  return;
	}
      }
    }
  }  
};
