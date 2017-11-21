#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  string convert(string s,int numRows){
    if(numRows==1){return s;}
    vector<vector<char> > zigzag (numRows,vector<char> ());
    bool downflag=true;
    int rowIndex=0;
    for(int i=0;i<s.size();i++){
      zigzag[rowIndex].push_back(s[i]);
      if(downflag){
	if(rowIndex==numRows-1){
	  downflag=false;
	  rowIndex--;
	}else{
	  rowIndex++;
	}
      }else{
	if(rowIndex==0){
	  downflag=true;
	  rowIndex++;
	}else{
	  rowIndex--;
	}
      }
    }
    string ans="";
    for(int i=0;i<zigzag.size();i++){
      for(int j=0;j<zigzag[i].size();j++){
	ans+=zigzag[i][j];
      }
    }
    return ans;
  }
};
