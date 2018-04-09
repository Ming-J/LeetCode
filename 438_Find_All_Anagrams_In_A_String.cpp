#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    if(p.size() > s.size()) return ans;
    vector<int> pArray = getAma(p);
    vector<int> subArray = getAma(s.substr(0,p.size()));
    if(pArray == subArray) ans.push_back(0);
    for(size_t i = 1; i < s.size() - p.size() + 1; ++i){
      --subArray[s[i-1]-'a'];
      ++subArray[s[i+p.size()-1]-'a'];
      if(pArray == subArray) ans.push_back(i);
    }
    return ans;
  }
private:
  vector<int> getAma(string p){
    vector<int> ca(26,0);
    for(char c : p) ++ca[c-'a'];
    return ca;
  }
  
  int* getAmagrams(string p){
    static int carray[26] = {0};
    for(char c : p){
      carray[c-'a']++;
    }
    return carray;
  }
};

int main(){
  Solution test;
  vector<int> res = test.findAnagrams("cbaebabacd","abc");
  for(auto re : res){
    cout<<re<<endl;
  }
}
