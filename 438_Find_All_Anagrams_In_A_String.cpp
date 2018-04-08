#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    int *ca = getAmagrams(p);
    for(int& a : ca){
      cout<<a<<endl;
    }
    return ans;
  }
private:
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
  vector<int> res = test.findAnagrams("adsfsdfa","ab");
}
