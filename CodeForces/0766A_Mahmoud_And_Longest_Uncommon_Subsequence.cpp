#include <iostream>
using namespace std;

int main(){
  string s1, s2;
  cin>>s1>>s2;
  if(s1 == s2){
    cout<<-1<<endl;
  }else{
    int output = (s1.size()>s2.size())? s1.size( ): s2.size();
    cout<<output<<endl;
  }
  return 0;
}
