#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    string simplify = "";
    stringstream ss(path);
    vector<string> q; 
    string token;
    while(getline(ss,token,'/')){
      if(token == "."|| token == "") continue;
      if(token == ".."){
	if(!q.empty()) q.pop_back();
	continue;
      }
      q.push_back(token);
    }
    for(string t:q) simplify += "/" + t;
    return (simplify.empty())?"/":simplify;
  }
};

int main(){
  Solution test;
  cout<<test.simplifyPath("/a/./b/../../c/")<<endl;
}
