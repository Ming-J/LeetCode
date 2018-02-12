#include <iostream>
using namespace std;

void reverse(string &a){
  int i = 0;
  int j = a.size() - 1;
  while(i < j){
    swap(a[i],a[j]);
    i++;
    j--;
  }
}

class Solution {
public:
  string addBinary(string a, string b) {
    string ans(max(a.size(),b.size())+1,'0');
    reverse(a);
    reverse(b);
    for( int i = 0; i < ans.size(); i++){
      char one = 0, two = 0, carry = 0;
      carry = ans[i]-'0';
      if(a.size() > i){
	one = a[i]-'0';
      }
      if(b.size() > i){
	two = b[i]-'0';
      }
      //cout<<one<<' '<<two<<' '<<carry<<endl;
      char tot = carry + one + two;
      if( tot > 1 ){
	ans[i+1] = 1+'0';
	tot %= 2;
      }
      ans[i] = tot+'0';
      if( i == ans.size() - 1 && tot == 0){
	ans = ans.substr(0,ans.size()-1);
      }
    }
    reverse(ans);
    return ans;
  }
};

int main(){
  Solution test;
  cout<<test.addBinary("11","0");
}
