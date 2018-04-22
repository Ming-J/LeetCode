#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isPossible(vector<int>& nums) {
    unordered_map<int,int> freq,sequ;
    //Getting the frequency of character
    for(int n : nums){
      if(freq.find(n)==freq.end()){
	freq.insert(make_pair(n,1));
      }else{
	++freq[n];
      }
    }
    
    for(int n : nums){
      if(freq[n] == 0){
	continue;
      }else if(sequ[n] > 0){ //Meaning we can append to the end of the sequence
	--sequ[n];
	++sequ[n+1];
      }else if(freq[n+1] > 0 && freq[n + 2] > 0){
	//unable to connect to previous sequence, we check if the
	//sequence can be form to three
 	--freq[n+1];
	--freq[n+2];
	++sequ[n+3];
      }else{
	//unable to form a sequence of length 3
	return false;
      }
      --freq[n];
    }
    return true;
  }
};

int main(){
  Solution test;
  vector<int> input = {1,2,3,3,4,5};
  test.isPossible(input);
}
