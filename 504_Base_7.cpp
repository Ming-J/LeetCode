#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution{
public:
  string converToBase(int num){
    int power=1;
    int value=7;
    int reminder=0;
    string ans="";
    while(num>0){
      value=num/7;
      reminder=num%7;
      cout<<value<<" "<<reminder<<endl;
      num=value;
      stringstream ss;
      ss<<reminder;
      ans.insert(0,ss.str());
      //oss<<reminder<<ans;
      cout<<ans<<endl;
    }
    //cout<<oss.str()<<num<<endl;
    return ans;
  }
};

int main(){
  Solution testing;
  testing.converToBase(100);
}
