#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int longestPalindrome(string s){
    vector<int> hash(256,0);
    for(int i=0;i<s.size();i++){
      hash[s[i]]++;
    }
    int sum=0;
    int oddCount=0;
    for(int i=0;i<hash.size();i++){
      if(hash[i]%2==0){
	sum+=hash[i];
      }else{
	oddCount++;
	sum+=hash[i]-1;
      }
    }
    if(oddCount>0){sum++};
    return sum;
  }
};
