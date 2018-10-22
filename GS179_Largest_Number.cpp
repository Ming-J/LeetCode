#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
  [0,0]   0
   
*/
class Solution {
public:
  string largestNumber(vector<int> &nums) {
    auto cmp = [](int &lhs, int &rhs) {
      string lhsStr = to_string(lhs);
      string rhsStr = to_string(rhs);
      return lhsStr + rhsStr > rhsStr + lhsStr;
    };
    sort(nums.begin(), nums.end(), cmp);
    string result;
    for (int n : nums) {
      if(n != 0||!result.empty()){
        result += to_string(n);
      }
    }
    return !result.empty()?result:"0";
  }
};
