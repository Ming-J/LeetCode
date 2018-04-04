#include <iostream>
#include <vector>
using namespace std;
/*
  Brute Force O(2^n) n = 20  AC 585 ms
  Space Complxity:O(n)

  DP 

  Vi to denote the possible sums by using first i element
  v0 = {0}
  vi = {vi-1 + ai} U {Vi-1 - ai}
  Check target in Vn

  DP works because |vn| <= S <<O(2^n)

  input: [ 1,1,1,1,1] t = 3
  
  2^5 = 32 combination, but total 6 distinct value, max is 11(2*5+1)
  
   2D dp 
   ways[i][j] # of ways to sum up to j using nums[0~i]
   ways[i][j] = ways[i-1][j-nums[i]] 
              + ways[i-1][j+nums[i]]

   init: ways[-1][0] = 1 one way to sum up 0, do nothing
        ways[n-1][S]

   Push:scan last push down    Pull
 
   Subset Sum
   P denotes a set of nums have a + sign 
   N denotes a set of nums have a - sign
   P U N = { a1,a2,...an}
   Sum(P) - sum(N) = target 
   Sum(P) - Sum(N) + Sum(P) + Sum(N) = target + SUm(P) + sum(N)
   2 * Sum(P) = target + sum(a)

   Sum(P) = (target + sum(a) ) / 2 0-1 Knapsack problem
   Sumpler question: using the given nums, can be sum up to target?
   

*/
class Solution{
public:
  int findTargetSumWays(vector<int>& nums, int s){
    int count = 0;
    helper(nums,0,s,0,count);
    return count;
  }
  void helper(vector<int>& nums,int i,int s,int cur,int &count){
    if(i == nums.size()){
      if(cur == s) ++count;
    }else{
      helper(nums,i+1,s,cur+nums[i],count);
      helper(nums,i+1,s,cur-nums[i],count);
    }
  }
};

int main(){
  vector<int> input{1,1,1,1,1};
  Solution test;
  cout<<test.findTargetSumWays(input,3);
}
