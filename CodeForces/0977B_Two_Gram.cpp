#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

string twoGram(string s, int n){
  unordered_map<string,int> map;
  for(int i = 0; i < n - 1; ++i){
    string sub = s.substr(i,2);
    map[sub]++;
  }
  auto cmp = [](pair<string,int>lhs,pair<string,int>rhs){
	       return lhs.second < rhs.second;
	     };
  return max_element(map.begin(),map.end(),cmp)->first;
}

int main(){
  int n;
  string input;
  cin>>n;
  cin>>input;
  cout<<twoGram(input,n)<<endl;
}
