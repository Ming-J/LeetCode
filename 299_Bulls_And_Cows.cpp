#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
      int a=0,b=0;
      vector<int> hash(guess.size(),0);
      for(int i=0;i<guess.size();i++){
	char temp=checkstring(i,guess[i],secret,hash);
	if(temp=='A'){
	  a++;
	}
	if(temp=='B'){
	  b++;
	}
      }
      return to_string(a)+'A'+to_string(b)+'B';
    }

  char checkstring(int pos, char n, string secret,vector<int> &hash){
    if(secret[pos]==n){
      hash[pos]++;
      return 'A'; 
    }else{
      for(int i=0;i<secret.size();i++){
	if(i!=pos&&secret[i]==n&&hash[i]==0){
	  hash[i]++;
	  return 'B';
	}
      }
      return 0;
    }
  }
};

