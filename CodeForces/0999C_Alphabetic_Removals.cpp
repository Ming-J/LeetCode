#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  string str;
  cin>>str;
  string newStr = str;
  sort(newStr.begin(), newStr.end());
  char cur = newStr[k-1];
  int diff = newStr.find(cur);
  for(size_t i = 0; i < str.size(); ++i){
    if(str[i] == cur && diff < k){
      ++diff;
    }else if(str[i] > cur || str[i] == cur){
      cout<<str[i];
    } 
  }
}
