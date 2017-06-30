#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution{
public:
  int findComplement(int num){
    string bitstring=baseOf2(num);
    for(int i=0;i<bitstring.length();i++){
      if(bitstring[i]=='1'){
	bitstring[i]='0';
      }else{
	bitstring[i]='1';
      }
    }
    cout<<bitstring<<endl;
    int complement=0;
    int base2=0;
    int powercounter=0;
    for(int i=bitstring.length()-1;i>=0;i--){
      if(bitstring[i]=='1'){
	if(powercounter==0){
	  complement=complement+1;
	}else{
	  base2=1;
	  int counter=powercounter;
	  while(counter>0){
	    base2=base2*2;
	    counter--;
	  }
	}
	complement=complement+base2;
      }
      powercounter++;
    }
    return complement;
  }
  string baseOf2(int ten){
    int reminder=0;
    string number;
    while(ten>0){
      reminder=ten%2;
      ten=ten/2;
      stringstream ss;
      ss<<reminder;
      number.insert(0,ss.str());
    }
    return number;
  }
};

int main(){
  cout<<"Hello World"<<endl;
  Solution test;
  cout<<test.baseOf2(5)<<endl;
  cout<<test.findComplement(5)<<endl;
}
