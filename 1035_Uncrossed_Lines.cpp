#include <iostream>
#include <vector>
using namespace std;

/*
  Bottom Up Approach :
  Think about the recurision method
  lcs(a,b) =
    if a and b last character is same
       1 + lcs(a(-1),b(-1))
    if not same
       we do the max of lcs(a(-1),b) or lcs(a,b(-1))
  There are three recursive relationship that we need to figure out.
  same : dp[i][j] = dp[i-1]dp[j-1] + 1
  not Smae : dp[i][j] = max(dp[i-1][j],dp[i][j-1]); 
  so in dp structure
  ABZ
A 111
Z 112
B 122
*/

class Solution {
public:
  int maxUncrossedLines(vector<int> &A, vector<int> &B) {
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
    for (size_t i = 1; i < dp.size(); ++i) {
      for (size_t j = 1; j < dp[i].size(); ++j) {
        if (A[i - 1] == B[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return dp.back().back();
  }
};
