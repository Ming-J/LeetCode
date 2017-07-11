/*===================================================================
Given a non-empty string containing an out-of-order English
representation of digits 0-9, output the digits in ascending order.

Note: Input contains only lowercase English letters.  

Input is guaranteed to be valid and can be transformed to its original
digits. That means invalid inputs such as "abc" or "zerone" are not
permitted.

Input length is less than 50,000.  

Example 1: Input:
"owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
 ====================================================================*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution{
public:
  string originalDigits(string s){
    int carray[257]={0};
    vector<int> result;
    for(int i=0;i<s.size();i++){
       carray[s[i]]++;
      }
    if(carray['z']!=0){
      int diff=carray['z'];
      carray['z']=carray['z']-diff;
      carray['e']=carray['e']-diff;
      carray['r']=carray['r']-diff;
      carray['o']=carray['o']-diff;
      for(int i=0;i<diff;i++){
	result.push_back(0);
      }
    }
    if(carray['w']!=0){
      int diff=carray['w'];
      carray['t']=carray['t']-diff;
      carray['w']=carray['w']-diff;
      carray['o']=carray['o']-diff;
      for(int i=0;i<diff;i++){
	result.push_back(2);
      }
    }
    if(carray['g']!=0){
      int diff=carray['g'];
      carray['e']=carray['e']-diff;
      carray['i']=carray['i']-diff;
      carray['g']=carray['g']-diff;
      carray['h']=carray['h']-diff;
      carray['t']=carray['t']-diff;
      for(int i=0;i<diff;i++){
	result.push_back(8);
      }
    }
    if(carray['h']!=0){
      int diff=carray['h'];
      carray['t']=carray['t']-diff;
      carray['h']=carray['h']-diff;
      carray['r']=carray['r']-diff;
      carray['e']=carray['e']-diff;
      carray['e']=carray['e']-diff;
      for(int i=0;i<diff;i++){
	result.push_back(3);
      }
    }
    if(carray['u']!=0){
      int diff=carray['u'];
      carray['f']=carray['f']-diff;
      carray['o']=carray['o']-diff;
      carray['u']=carray['u']-diff;
      carray['r']=carray['r']-diff;
      for(int i=0;i<diff;i++){
	result.push_back(4);
      }
    }
    if(carray['x']!=0){
      int diff=carray['x'];
      carray['s']=carray['s']-diff;
      carray['i']=carray['i']-diff;
      carray['x']=carray['x']-diff;
      for(int i=0;i<diff;i++){
	result.push_back(6);
      }
    }
    if(carray['h']!=0){
      int diff=carray['h'];
      carray['t']=carray['t']-diff;
      carray['h']=carray['h']-diff;
      carray['r']=carray['r']-diff;
      carray['e']=carray['e']-diff;
      carray['e']=carray['e']-diff;
      for(int i=0;i<diff;i++){
	result.push_back(3);
      }
    }
    if(carray['o']!=0){
      int diff=carray['o'];
      carray['o']=carray['o']-diff;
      carray['n']=carray['n']-diff;
      carray['e']=carray['e']-diff;
      for(int i=0;i<diff;i++){
	result.push_back(1);
      }      
    }
    if(carray['f']!=0){
      int diff=carray['f'];
      carray['f']=carray['f']-diff;
      carray['i']=carray['i']-diff;
      carray['v']=carray['v']-diff;
      carray['e']=carray['e']-diff;
      for(int i=0;i<diff;i++){
	result.push_back(5);
      }
    }
    if(carray['s']!=0){
      int diff=carray['s'];
      carray['s']=carray['s']-diff;
      carray['e']=carray['e']-diff;
      carray['v']=carray['v']-diff;
      carray['e']=carray['e']-diff;
      carray['n']=carray['n']-diff;
      for(int i=0;i<diff;i++){
	result.push_back(7);
      }
    }
    if(carray['i']!=0){
      int diff=carray['i'];
      carray['n']=carray['n']-diff;
      carray['i']=carray['i']-diff;
      carray['n']=carray['n']-diff;
      carray['e']=carray['e']-diff;
      for(int i=0;i<diff;i++){
	result.push_back(9);
      }
    }
    sort(result.begin(),result.end());
    stringstream ss;
    for(int i=0;i<result.size();i++){
      ss<<result[i];
    }
    return ss.str();
  }
};

  int main(){
    Solution test;
    cout<<test.originalDigits("owoztneoer")<<endl;
    
  }
