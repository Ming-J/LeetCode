/*****************************************************************************
Given an integer, return its base 7 string representation.
*
*Example 1:
*  Input: 100
*  Output: "202"
*Example 2:
*  Input: -7
*  Output: "-10"
*Note: The input will be in range of [-1e7, 1e7].
******************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Solution{
public:
  string converToBase(int num){
    bool sign=false;
    int value=7;
    int reminder=0;
    string ans="";
    if(num==0){
      ans="0";
      return ans;
    }
    if(num<0){
      num=num*-1;
      sign=true;
    }
    while(num>0){
      value=num/7;
      reminder=num%7;
      num=value;
      stringstream ss;
      ss<<reminder;
      ans.insert(0,ss.str());
      cout<<ans<<endl;
    }
    if(sign==true){
      ans.insert(0,"-");
    }
    return ans;
  }
};

int main(){
  Solution testing;
  testing.converToBase(100);
}
