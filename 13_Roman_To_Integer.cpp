/*=========================================================================
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Going through the string, and add up accordingly. 
 =========================================================================*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int romanToInt(string s){
    enum roman {I=1,V=5,X=10,L=50,C=100,D=500,M=1000};
    unordered_map<string,int> romannum;
    romannum["I"]=1;
    romannum["V"]=5;
    romannum["X"]=10;
    romannum["L"]=50;
    romannum["C"]=100;
    romannum["D"]=500;
    romannum["M"]=1000;
    romannum["IV"]=4;
    romannum["IX"]=9;
    romannum["XL"]=40;
    romannum["XC"]=90;
    romannum["CD"]=400;
    romannum["CM"]=900;
    int result=0;
    for(int i=0;i<s.size();i++){
      string fir(1,s[i]);
      if(i<s.size()-1){
	string sec(1,s[i+1]);
	string combine=fir+sec;
	unordered_map<string,int>:: iterator got=romannum.find(combine);
	if(got!=romannum.end()){
	result=result+romannum[combine];
	i++;
      }else{
	result=result+romannum[fir];
      }
      }else{
	result=result+romannum[fir];
      }
    }
    return result;
  }
};

int main(){
  Solution result;
  result.romanToInt("MCMXCVI");
}
