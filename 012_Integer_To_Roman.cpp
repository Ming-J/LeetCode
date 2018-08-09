#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    map<int, char> roman;
    roman.insert(make_pair(1,'I'));
    roman.insert(make_pair(5,'V'));
    roman.insert(make_pair(10,'X'));
    roman.insert(make_pair(50,'L'));
    roman.insert(make_pair(100,'C'));
    roman.insert(make_pair(500,'D'));
    roman.insert(make_pair(1000,'M'));
    string rNum = "";
    for(int i = 0, j = 1000; i < 4; ++i, j /= 10){
      if(num >= j){
	int val = num / j;
	num -= j*val;
	if(i != 0 && (val == 4 || val == 9)){
	  if(val == 4){
	    rNum.push_back(roman[j]);
	    rNum.push_back(roman[j*5]);
	  }else{
	    rNum.push_back(roman[j]);
	    rNum.push_back(roman[j*10]);
	  }
	}else{
	  if(i != 0 && val >= 5){
	    rNum.append(1,roman[j*5]);
	    rNum.append(val-5,roman[j]);
	  }else{
	    rNum.append(val,roman[j]);
	  }
	}
      }
    }
    return rNum;
  }
};

int main(){
  Solution test;
  cout<<test.intToRoman(58)<<endl;
}
