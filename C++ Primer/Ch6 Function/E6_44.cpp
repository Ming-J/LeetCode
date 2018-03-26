#include <iostream>
using namespace std;
/*
Rewrite the isShorter function to be inline.

bool isShorter(const string &s1, const string &s2){
 return s1.size() < s2.size();
}
*/
inline bool isShorter(const string &s1, const string &s2){
    return s1.size() < s2.size();
}
int main(){
  string str1 = "abcqweqw";
  string str2 = "asdfs";
  if(isShorter(str1,str2)){
    cout<<"str2 is longer"<<endl;
  }else{
    cout<<"str1 is longer"<<endl;
  }
}
