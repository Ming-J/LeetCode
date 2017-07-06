#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
  bool repeatedSubstringPattern(string s){
    int length=s.size();
    for(int i=length/2;i>=0;i--){
      if(length%i==0){
	string ssub=s.substr(0,i);
	int index=0;
	while(index<length/2){
	  if(ssub[index]==s[i+index+1]){

	  }
	  index++;
	}
      }
    }
  }
};

int main(){
  cout<<"Hello World"<<endl;
}
