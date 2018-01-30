#include <iostream>
using namespace std;

class Solution {
public:
  string licenseKeyFormatting(string S, int K) {
    string res="";
    int charC = 0;
    for(int i = 0; i < S.size(); i++){
      if(S[i] != '-'){
	charC++;
      }
    }
    int remind = K % charC;
    int i = 0;
    for(;remind>0; i++){
      if(S[i]!= '-'){
	remind--;
	res += S[i];
      }
    }
    res += '-';
    int hyp = 1;
    for(; i < S.size() ; i++){
      if( S[i] != '-'){	
	hyp++;
	res += S[i];
	if(hyp % K == 0){
	  res += '-';
	}
      }
    }
    return res;
  }
};

int main(){
  string S = "2-5g-3-J";
  Solution test;
  cout<<test.licenseKeyFormatting(S,2)<<endl;
}
