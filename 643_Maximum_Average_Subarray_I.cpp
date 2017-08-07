/*
Given an array consisting of n integers, find the contiguous subarray
of given length k that has the maximum average value. And you need to
output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].

The goal of this question is to return a max average of k element in
the given array.  Using the sliding door algorithm. Add up the sum to
the initial k. Then you will continue to remove first element of
subarray and add new value. Update the maxsum when the new sum is
greater.

Time Complexity: O(n)
Space Complexity: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  double findMaxAverage(vector<int>& nums, int k){
    int maxSum=0;
    int current=0;
    for(int i=0;i<nums.size();i++){
      if(i<k){
	current=current+nums[i];
	maxSum=current;
      }else{
	current=current-nums[i-k];
	current=current+nums[i];
      }
      if(current>maxSum){
	maxSum=current;
      }
    }
    return maxSum*1.0/k;
    //cout<<maxSum<<endl;
  }
};

int main(){
  int arr[6]={1,12,-5,-6,50,3};
  vector<int> input(arr,arr+sizeof arr/sizeof arr[0]);
  Solution test;
  cout<<test.findMaxAverage(input, 4)<<endl;
}
