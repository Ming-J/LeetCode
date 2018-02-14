#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int>& nums) {
    // Calculating Sum
    int arrSum = calculatingSum(nums);
    if( arrSum % 2 != 0) return false;
    // each partition will need to be this value
    int partitionTarget = arrSum / 2;
    return dpSubsetSum(nums, partitionTarget);
  }
  int calculatingSum(vector<int> & nums){
    return accumulate(nums.begin, nums.end(), 0);
  }

  bool dpSubsetSum(vector<int>& nums, int target){
    //vector< vector<bool> > dp(target+1, vector<bool> (nums.size(),false));
    bool dp[nums.size()+1][target+1];
    dp[0][0] = true;
    //if sum is not zero and subset is 0, impossible
    for( int i = 1; i <= target; i++){
      dp[0][i] = false;
    }
    //if sum is zero, we can make the empty subset to make sum 0
    for(int i = 0; i <= nums.size(); i++){
      dp[i][0] = true;
    }
    for( int i = 1; i <= nums.size(); i++){ 
      for(int j = 1; j <= target; j++){
	//copy from top
	dp[i][j] = dp[i-1][j];

	if( dp[i][j] == false && j >= nums[i-1]){
	  dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
	}
      }
    }
    return dp[nums.size()][target];
  }
/*To check if the array contain a subset sum equal to target
  using recursion, 
  two situtation
  1. incuding the last element 2. excluding the last element
  Base Case: when our target is equal to 0
  Base Case: When we are in our last element of the array and target is not 0
*/
  bool subsetSum(vector<int> & nums,int n, int target){
    if( target == 0 ){
      return true;		
    }
    if( n == nums.size() && target != 0 ){
      return false;
    }
    if( target < 0) return subsetSum(nums,n+1,target);
    return subsetSum(nums,n+1,target)||subsetSum(nums,n+1,target-nums[n]);
  }
};

int main(){
  const string s1 = "Hello World";
  cout<<s1<<endl;
  for( auto &c : s1){
    cout<<c;
  }
  cout<<s1<<endl;
}
