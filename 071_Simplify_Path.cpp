#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  string simplifyPath(string path){
    vector<string> deck;
    size_t subStart = 0, found = 0;
    while(subStart < path.size() &&
	  (found = path.find('/',subStart))!= string::npos){
      //cout<<found<<endl;
      size_t length = found-subStart;
      length = (length < path.size())?length:0;
      string substr = path.substr(subStart,length);
      checkStack(deck,substr);
      subStart = found+1;
    }
    checkStack(deck,path.substr(subStart));
    return retStr(deck);
  }

  string retStr(vector<string>& stack){
    string path = "";
    for(string s:stack){
      path += "/" + s;
    }
    return path.empty()?"/":path;
  }
  
  void checkStack(vector<string>& stack, string s){
    if(s==""||s==".") return;
    if(s==".."){
      if(!stack.empty()) stack.pop_back();
      return;
    }
    stack.push_back(s);
  }
  
};

int main(){
  Solution s;
  cout<<s.simplifyPath("")<<endl;;
  string t = "asd";
  cout<<t.substr(1,-1)<<endl;
}
