#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
  int n;
  cin>>n;
  unordered_map<string,int> dict;
  for(int i = 0; i < n; ++i){
    string s;
    cin>>s;
    ++dict[s];
  }
  if(dict.size() == 1){
    cout<<dict.begin()->first<<endl;
    return 0;
  }
  if(dict.begin()->second > (++dict.begin())->second){
    cout<<dict.begin()->first<<endl; 
  }else{
    cout<<(++dict.begin())->first<<endl;
  }
}
