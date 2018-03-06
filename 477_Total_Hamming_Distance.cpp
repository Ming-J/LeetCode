#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  //iterating through all pairs, then sum all bit counts
  //time complexity: O(N^2) 
  int totalHammingDistanceBruteForce(vector<int>& nums){
    int xoo = 0;
    for(int i = 0; i < nums.size(); ++i){
      for(int j = i + 1; j < nums.size();++j){
	xoo += bitset<32>(nums[i] ^ nums[j]).count();
      }
    }
    return xoo;
  }

  // total Distance += one(i) * zero(i)
  // Time Complexity: O(32*n) = O(n)
  int totalHammingDistance(vector<int>& nums){
    int hammer = 0;
    for(int i = 0; i < 32; ++i ){
      int oneBits = 0;
      for(size_t j = 0; j < nums.size(); ++j){
	if( ( (nums[j]>>i) & 1 ) == 1){
	  oneBits++;
	}
      }
      hammer += oneBits * (nums.size() - oneBits);
    }
    return hammer;
  }
};

int main(){
  Solution test;
  vector<int> input = {4,14,2};
  cout<<test.totalHammingDistance(input);
}
