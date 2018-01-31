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
    int kcounter = 0;
    res.resize( charC + (charC-1)/K, '_' );
    int rezi = res.size() - 1;
    cout<<res.size()<<' '<<res<<' '<<charC<<endl;
    for(int i = S.size() - 1; i >= 0; i--){
      //cout<<S[stri]<<' '<<res[i]<<endl;
      if(S[i] != '-'){
	res[rezi] = S[i];
	kcounter++;
	rezi--;
	if( kcounter >= K && kcounter % K == 0){
	  res[rezi] = '-';
	  rezi--;
	}
      }
      cout<<rezi<<' '<<i<<' '<<res<<' '<<S[i]<<' '<<res[rezi]<<endl;
    }
    cout<<res<<"ewraw"<<endl;
    return res;
  }
};

int main(){
  string S = "5F3Z-2e-9-w";
  Solution test;
  cout<<test.licenseKeyFormatting(S,4)<<endl;
}
