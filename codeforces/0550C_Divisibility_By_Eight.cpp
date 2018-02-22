#include <iostream>
#include <string>
using namespace std;

class Eight{
private:
  string value;
public:
  Eight(string s){
    value = s;
    string div;
    if(recur(value,"",div)){
      cout<<"YES"<<endl<<div;
    }else{
      cout<<"NO"<<endl;
    }
  }
  
  bool recur(string val, string digit,string &div){
    if(!digit.empty()&&stoi(digit) % 8 == 0){
      div = digit;
      return true;
    }
    if(val == "" || (!digit.empty()&&stoi(digit) >= 1000)){
      return false;
    }
    return recur(val.substr(1),digit+val[0],div)||recur(val.substr(1),digit,div);
  }

  
  string cal(){
    int dp[value.size()][8]= {0};
    for(size_t i  = 0; i < value.size(); ++i){

      dp[i][value[i] % 8 ] = 1;
    }
    for( auto &s : dp ){
      for(auto k : s){
	cout<<k<<' ';
      }
      cout<<endl;
    }
    return "";
  }
  string getValue(){
    return value;
  }
};

int main(){
  string va;
  cin>>va;
  Eight v(va);
  //cout<<v.getValue()<<endl;
  //v.cal();
}
