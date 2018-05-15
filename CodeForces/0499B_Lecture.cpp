#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  unordered_map<string, string> dict;
  for(int i = 0; i < m; ++i){
    string l1,l2;
    cin>>l1>>l2;
    dict[l1] = l2;
  }
  string res = "";
  for(int i = 0; i < n; ++i){
    string word;
    cin>>word;
    res += (dict.find(word)->second.size() <
	    word.size())? dict[word] : word;
    res += ' ';
  }
  res.erase(res.end()-1,res.end());
  cout<<res<<endl;
}
