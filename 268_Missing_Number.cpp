#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int sum=0;
    for(int i=0; i<nums.size(); i++){
      sum += i;
      sum -= nums[i];
    }
    return sum+nums.size();
  }
};

int main(){
  vector<int> input = {9,6,4,2,3,5,7,0,1};
  Solution test;
  cout << test.missingNumber(input) <<endl;
  return 0;
}
