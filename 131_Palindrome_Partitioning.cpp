#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
  vector<vector<string>> partition(string s) {
    if(s.empty()) return {};
    vector< vector<string> > ans;
    vector<string> cur;
    helper(ans,cur,s);
    return ans;
  }

  void helper(vector< vector<string> >& ans,vector<string>& cur,
	      string s){
    if(s.empty()){
      ans.push_back(cur);
      return;
    }
    for(int i = 1; i <= s.size(); ++i){
      string temp = s.substr(0,i);
      cout<<"t"<<temp<<endl;
      if(palindrome(temp)){
	cout<<"dsad "<<temp<<" "<<s.substr(i)<<endl;
	cur.push_back(temp);
	helper(ans,cur,s.substr(i));
	cur.pop_back();
      }
    }
  }

private:
  bool palindrome(string s){
    int i = 0, j = s.size() - 1; 
    while(i <= j){
      if(s[i++] != s[j--]) return false;
    }
    return true;
  }
};


int main(){
  Solution test;
  vector< vector<string> > ans = test.partition("aab");
  for( auto v : ans){
    for(auto s : v){
      cout<<s<<endl;
    }
    cout<<endl;
  }
}
