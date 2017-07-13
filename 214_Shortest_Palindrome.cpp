/*================================================================

Given a string S, you are allowed to convert it to a palindrome by
adding characters in front of it. Find and return the shortest
palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".

logic for this problem is say we have:
-Sting S
-Added string in front is P

   PS= PQP'  where QP'=S 
So if P and P' is palindrome, Q is also Palindrome

We would like P as short as possible, so Q has to be as long as
possible.

S=QP apprend the reverse SS'=QPP'Q' We know Q is a Palindrome so
SS'=QPP'Q now what we want to find the longest Q where Q is the prefix
of SS' also a suffix of SS'.
 =================================================================*/
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  string shortestPalindrome(string s){
    if(s.size()==0){
      return "";
    }
    string reverseS=reversestring(s);
    string rev=s+"#"+reverseS;
    vector<int> partialtable=kmptable(rev);
    int revsize=rev.size();
    int ptsize=partialtable.size();
    int suffixindex=partialtable[ptsize-1];
    if(suffixindex==revsize){
      return s;
    }
    //string sufix=rev.substr(revsize-suffixindex,suffixindex);
    string prefix=reverseS.substr(0,reverseS.size()-suffixindex);
    //cout<<rev<<" "<<sufix<<" "<<prefix<<endl;
    return prefix+s;
  }
  string reversestring(string s){
    string reverse="";
    for(int i=s.size()-1;i>=0;i--){
      reverse=reverse+s[i];
    }
    return reverse;
  }

  vector<int>kmptable(string s){
    vector<int> prefix(s.size(),0);
    int i=1;
    int j=0;
    while(i<prefix.size()){
      if(s[i]==s[j]){
	prefix[i]=j+1;
	i=i+1;
	j=j+1;
      }else{
	if(j!=0){
	  j=prefix[j-1];
	}else{
	  prefix[i]=0;
	  i=i+1;
	}
      }
    }
    return prefix;
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
    return prefixtable;
  }
};

int main(){
  Solution test;
  //test.shortestPalindrome("ABAB");
  test.kmpPrefix("ABAB");
  test.kmptable("ABAB");
  cout<<test.shortestPalindrome()<<end;
}
