#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution{
public:
  bool wordPattern(string pattern, string str){
    unordered_map<char,string> patternmap;
    for(int i=0;i<str.size();i++){
      if(
      
    }
    cout<<pattern<<" "<<str<<endl;
  }
};

int main(){
  Solution test;
  test.wordPattern("abba","dog cat cat dog");
}
