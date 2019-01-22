#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  /**
   * @param A: A string
   * @param B: A string
   * @return: the length of the longest common substring.
   */
  int longestCommonSubstring(string &A, string &B) {
    // write your code here
    unordered_set<string> subs;
    int maxLength = 0;
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
    for (size_t i = 1; i <= A.size(); i++) {
      for (size_t j = 1; j <= B.size(); ++j) {
        if (A[i - 1] == B[j - 1]) {
          dp[i][j] += dp[i - 1][j - 1] + 1;
        }
        maxLength = max(maxLength, dp[i][j]);
      }
    }
    cout << ' ' << ' ' << ' ';
    for (auto i : B) {
      cout << i << ' ';
    }
    cout << endl;
    int k = 0;
    for (auto i : dp) {
      if (k == 0)
        cout << ' ' << ' ';
      else {
        cout << A[k - 1] << ' ';
      }
      k++;
      for (auto j : i) {
        cout << j << ' ';
      }
      cout << endl;
    }
    return maxLength;
  }

  void subString(unordered_set<string> &subs, string original, int index,
                 string sub) {
    subs.insert(sub);
    if (index == original.size()) {
      return;
    }
    if (sub.size() != 0) {
      subString(subs, original, index + 1, sub + original[index]);
    } else {
      subString(subs, original, index + 1, sub);
      subString(subs, original, index + 1, string(1, original[index]));
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution test;
  string A = "abccccccccccde";
  string B = "dbccccccabccde";
  test.longestCommonSubstring(A, B);
  cout << "D" << endl;
  return 0;
}
