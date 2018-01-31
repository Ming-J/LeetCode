#include <iostream>
#include <string>
using namespace std;
/* Traverse through the string, count the number of character,
 * creating an attional string and iterating through the back to build
 * the new string, inserting '-' when it's neccessary. By using an k
 * counter we can know where to insert '-'  */
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
    //cout<<res.size()<<' '<<res<<' '<<charC<<endl;
    for(int i = S.size() - 1; i >= 0; i--){
      //cout<<S[stri]<<' '<<res[i]<<endl;
      if(S[i] != '-'){
	res[rezi] = isalpha(S[i]) ? toupper(S[i]) : S[i] ;
	kcounter++;
	rezi--;
	if( kcounter >= K && kcounter % K == 0 && rezi > 0 ){
	  res[rezi] = '-';
	  rezi--;
	}
      }
      //cout<<rezi<<' '<<i<<' '<<res<<' '<<S[i]<<' '<<res[rezi]<<endl;
    }
    return res;
  }
};

int main(){
  string S = "5F3Z-2e-9-w";
  int k = 2;
  Solution test;
  cout<<test.licenseKeyFormatting(S,4)<<endl;
  cout<<test.licenseKeyFormatting("a-----a",k)<<endl;
}
