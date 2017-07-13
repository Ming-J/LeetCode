#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  string shortestPalindrome(string s){
    if(s.size()==0){
      return "";
    }
    string rev=s+reversestring(s);
    vector<int> partialtable=kmpPrefix(rev);
    int revsize=rev.size();
    int ptsize=partialtable.size();
    int suffixindex=partialtable[ptsize-1];
    if(suffixindex==revsize){
      return s;
    }
    
    string sufix=rev.substr(revsize-suffixindex,suffixindex);
    string prefix=reversestring(s).substr(0,reversestring(s).size()-sufix.size());
    cout<<rev<<" "<<sufix<<" "<<prefix<<endl;
    return prefix+s;
  }
  string reversestring(string s){
    string reverse="";
    for(int i=s.size()-1;i>=0;i--){
      reverse=reverse+s[i];
    }
    return reverse;
  }
  vector<int> kmpPrefix(string s){
    vector<int> prefixtable(s.size(),0);
    int index=1;
    int sindex=0;
    prefixtable[0]=0;
    for(index=1,sindex=0;index<s.size();++index){
      while(sindex>0&&s[index]!=s[sindex]){
	sindex=prefixtable[sindex-1];
      }
      if(s[index]==s[sindex]){
	sindex++;
      }
      prefixtable[index]=sindex;
    }
    for(int i=0;i<prefixtable.size();i++){
      cout<<s[i]<<" "<<prefixtable[i]<<endl;
    }
    return prefixtable;
  }
};

int main(){
  Solution test;
  //test.shortestPalindrome("ABAB");
  //test.kmpPrefix(test.shortestPalindrome("ABAB"));
  cout<<test.shortestPalindrome("aaaaa")<<endl;
}
