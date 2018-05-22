#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    //sizeOf return bytes, 1 bytes is 8 bits
    int bitSize = sizeof(int) * 8;
    vector<int> holdsBit(bitSize,0);
    for(size_t i = 0; i < nums.size(); ++i){
      for(int j = 0; j < bitSize; ++j){
	if((nums[i] & (1<<j)) != 0){
	  ++holdsBit[j];
	}
      }
    }
    int single = 0;
    for(size_t i = holdsBit.size() - 1; i < holdsBit.size(); --i){
      single |= holdsBit[i]%3;
      if(i != 0) single = single<<1;
    }
    return single;
  }
};

int main(){
  vector<int> input = {2,2,2,1000000,100,100,100};
  Solution test;
  test.singleNumber(input);
}
