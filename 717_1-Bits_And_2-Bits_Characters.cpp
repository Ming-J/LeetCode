#include <iostream>
using namespace std;

class Solution{
public:
  bool isOneBitCharacter(vector<int>& bits){
    // if it's 00 then is ont bits
    // if it's 10 the it cound be 1 or 2
    bool oneOrTwo = false;
    for( size_t i = 0; i < bits.size(); ++i){
      if(bits[i] == 0){
	oneOrTwo = true;
      }else{
	oneOrTwo = false;
	++i;
      }
    }
    return oneOrTwo;
  }
};
