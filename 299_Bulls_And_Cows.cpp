#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
      vector<bool> hash(guess.size(),false);
      int a=checkA(guess,secret,hash);
      int b=checkB(guess,secret,hash);
      return to_string(a)+'A'+to_string(b)+'B';
    }

  //checking cow
  int checkA(string guess, string secret, vector<bool> & flags){
    int n=0;
    for(size_t i=0;i<guess.size();i++){
      if(secret[i]==guess[i]){
	n++;
	flags[i]=true;
      }
    }
    return n;
  }
  //checking bull
  int checkB(string guess, string secret,vector<bool> &flags){
    vector<int> hash(10,0);
    for(size_t i=0;i<secret.size();i++){
      if(!flags[i]){
	hash[secret[i]-'0']++;
      }
    }
    int n=0;
    for(size_t i=0;i<guess.size();i++){
      if(!flags[i]){
	if(hash[guess[i]-'0']-->0){
	  n++;
	}
      }
    }
    return n;
  }
};

