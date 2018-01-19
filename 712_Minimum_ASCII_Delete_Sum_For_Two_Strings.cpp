#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
    vector<int> v1(0,26);
    vector<int> v2(0,26);
    for( int i = 0 ; i < s1.size(); i++){
      v1[s1[i]-'a'] ++;
    }
    for( int i = 0 ; i < s2.size(); i++){
      v2[s2[i]-'a'] ++;
    }
    
  }
};
