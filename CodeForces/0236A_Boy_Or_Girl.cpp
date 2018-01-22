#include <iostream>
#include <vector>
using namespace std;

int main(){
  string name;
  cin>>name;
  vector<int> chrArr(26,0);
  for( int i=0;i<name.size();i++){
    chrArr[name[i]-'a']++;
  }
  int c = 0;
  for(auto n : chrArr){
    if( n > 0){
      c++;
    }
  }
  if(c%2==0){
    cout<<"CHAT WITH HER!"<<endl;
  }else{
    cout<<"IGNORE HIM!"<<endl;
  }
}
