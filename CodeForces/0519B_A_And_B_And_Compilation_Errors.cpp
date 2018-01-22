#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
  int n;
  cin>>n;

  unordered_map<int,int> hash;
  int temp;
  for( int i = 0; i < n; i++){
    cin>>temp;
    hash[temp]++;
  }
  unordered_map<int,int> hash1;
  for( int i = 0; i < n-1; i++){
    cin>>temp;
    hash1[temp]++;
  }
  for(const auto it : hash){
    if(hash1[it.first]!=it.second){
      cout<<it.first<<endl;
    }
  }
  hash.erase(hash.begin(),hash.end());
  for( int i = 0; i < n-2; i++){
    cin>>temp;
    hash[temp]++;
  }
  for(const auto it : hash1){
    if(hash[it.first]!=it.second){
      cout<<it.first<<endl;
    }
  }
  return 0;
}
