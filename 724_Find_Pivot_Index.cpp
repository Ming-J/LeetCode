#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    if( nums.size() == 1){
      return 0;
    }
    if( nums.size() == 0){
      return -1;
    }
    vector<int> sums(nums.size(),0);
    vector<int> sumsRev(nums.size(),0);
    sumArray(sums,nums);
    sumArrayRev(sumsRev,nums);
    for(int i = 0; i < sums.size(); i++){
      int left = sumsRev.front() - sumsRev[i];
      int right = sums.back() - sums[i];
      if( left == right){
	return i;
      }
    }
    return -1;
  }

  void sumArray(vector<int>& sumArr, vector<int>& nums){
    int sum = 0;
    for(int i=0; i < nums.size(); i++){
      sum += nums[i];
      sumArr[i] = sum;
    }
  }
  void sumArrayRev(vector<int>& sumArr, vector<int>& nums){
    int sum = 0;
    for(int i = nums.size() - 1; i >= 0; i--){
      sum += nums[i];
      sumArr[i] = sum;
    }
  }
};

int main(){
  vector<int> input = {-1,-1,-1,0,1,1};
  Solution test;
  cout<<test.pivotIndex(input)<<endl;
}
