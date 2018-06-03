#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<string> strs(n);
  for(auto& s:strs) cin>>s;
  //Sorting strs by length
  sort(strs.begin(),strs.end(),
       [](string lhs, string rhs){ return lhs.size()<rhs.size();});
  for(size_t i = 1; i < strs.size(); ++i){
    if(strs[i].find(strs[i-1]) == string:: npos){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  for(string& s: strs) cout<<s<<endl;
  return 0;
}
