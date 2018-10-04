#include <iostream>
using namespace std;

class Phone{
public:
  Phone(int c, string s): cards(c), num(s) {
    for(char c : s) ++count[c-'0'];
  }

  int calculate(){
    int pn = 0;
    int nonEight = cards - count[8];
    int eight = count[8];
    while(eight > 0){
      --eight;
      if(nonEight >= 10){
	nonEight -= 10;
      }else{
	if(eight + nonEight >= 10){
	  eight -= (10-nonEight);
	  nonEight = 0;
	}else{
	  break;
	}
      }
      ++pn;
    }
    return pn;
  }

  
  // for(int i = count[i]; i < 10; ++i){
  // cout<<i<<' '<<count[i]<<endl;
  //}
  //return 0;
  //}
private:
  int cards;
  string num;
  int count [10] = {};
};

int main(){
  int c = 11;
  string s = "31415926535";
  cin>>c;
  cin>>s;
  Phone p(c,s);
  cout<<p.calculate()<<endl;
}
