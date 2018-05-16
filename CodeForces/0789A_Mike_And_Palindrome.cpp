#include <iostream>
using namespace std;

int main(){
  string s;
  cin>>s;
  int lo = 0;
  int hi = s.size() - 1;
  bool once = false;
  while(lo<=hi){
    if(s[lo] != s[hi]){
      if(once){
	cout<<"NO"<<endl;
	return 0;
      }
      once = true;
    }
    ++lo;
    --hi;
  }
  if(once || (!once && s.size() % 2 == 1)) cout<<"YES";
  else cout<<"NO";
  return 0;
}
