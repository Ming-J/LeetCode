#include <iostream>
#include <string>
using namespace std;

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string word;
    cin>>word;
    if(word.length()>10){
      cout<<word.substr(0,1)+to_string(word.length()-2)+word.substr(word.length()-1);
    }else{
      cout<<word;
    }
    cout<<endl;
  }
}
